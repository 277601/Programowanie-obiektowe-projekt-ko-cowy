#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Task.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QTextCharFormat>
#include "datetime_dialog.h"
#include <QListWidgetItem>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800,600);
    deadlineTimer = new QTimer(this);
    connect(deadlineTimer, &QTimer::timeout, this, &MainWindow::checkDeadlines);
    deadlineTimer->start(10000);

    connect(ui->actionSettings, &QAction::triggered, this, &MainWindow::openSettingsDialog);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->editTaskButton, &QPushButton::clicked, this, &MainWindow::on_editButton_clicked);
    connect(ui->removeTaskButton, &QPushButton::clicked, this, &MainWindow::on_removeButton_clicked);
    connect(ui->doneTaskButton, &QPushButton::clicked, this, &MainWindow::markTaskAsDone);
    connect(ui->freedayButton, &QPushButton::clicked, this, &MainWindow::markDayAsFree);
    connect(ui->calendarWidget, &QCalendarWidget::selectionChanged, this, [=]() {
        updateTaskList(ui->calendarWidget->selectedDate());
    });

    updateTaskList(ui->calendarWidget->selectedDate());
}

MainWindow::~MainWindow() {
    delete ui;
}
//Tu jest menubar
void MainWindow::openSettingsDialog() {
    QMessageBox::information(this, "Ustawienia", "Tutaj możesz dodać swoje opcje konfiguracyjne.");
}

//Ta funkcja będzie przypisywać zadania
void MainWindow::on_addButton_clicked() {
    bool ok;
    QString text = QInputDialog::getText(this, "Dodaj zadanie", "Treść zadania:", QLineEdit::Normal, "", &ok);
    if (!ok || text.isEmpty()) return;

    DateTimeDialog dlg(this);
    if (dlg.exec() != QDialog::Accepted)
        return;

    QDateTime deadline = dlg.selectedDateTime();
    QDate taskDate = deadline.date();

    Task newTask(text, deadline, false);
    tasks[taskDate].append(newTask);
    updateTaskList(taskDate);
}

// Ta funkcja będzie edytować zadania
void MainWindow::on_editButton_clicked() {
    int selectedRow = ui->taskListWidget->currentRow();
    if (selectedRow >= 0) {
        QDate currentDate = ui->calendarWidget->selectedDate();
        QString existingTask = ui->taskListWidget->item(selectedRow)->text();

        bool dialogAccepted;
        QString updatedTaskText = QInputDialog::getText(this, "Edytuj zadanie", "Nowa treść:", QLineEdit::Normal, existingTask, &dialogAccepted);

        if (dialogAccepted) {
            if (!updatedTaskText.isEmpty()) {
                tasks[currentDate][selectedRow] = updatedTaskText;
                updateTaskList(currentDate);
            }
        }
    }
}
// Ta funkcja będzie usuwać zadania kiedy będą one wykonano
void MainWindow::on_removeButton_clicked() {
    int row = ui->taskListWidget->currentRow();
    if (row < 0) {
        return ;
    }

    bool ok;
    QString password = QInputDialog::getText(this, "Potwierdzenie usunięcia",
                                             "Podaj hasło administratora:",
                                             QLineEdit::Password, "", &ok);

    if (!ok) {
        return;
    }

    if (password == "1108") {
        QDate date = ui->calendarWidget->selectedDate();
        tasks[date].removeAt(row);
        updateTaskList(date);
        QMessageBox::information(this, "Usunięto", "Zadanie zostało usunięte.");
    } else {
        QMessageBox::warning(this, "Błąd", "Niepoprawne hasło.");
    }
}

// Oznacz jako wykonane zadanie
void MainWindow::markTaskAsDone() {
    int row = ui->taskListWidget->currentRow();
    if (row >= 0) {
        QListWidgetItem *item = ui->taskListWidget->item(row);
        if (!item->text().startsWith("✅")) {
            item->setText("✅ " + item->text());
            item->setForeground(Qt::gray);
        }
    } else {
        QMessageBox::information(this, "Brak zadania", "Wybierz zadanie z listy.");
    }
}

// Zaznacz dzień jako wolny (z hasłem)
void MainWindow::markDayAsFree() {
    bool ok;
    QString password = QInputDialog::getText(this, "Dzień wolny",
                                             "Podaj hasło administratora:",
                                             QLineEdit::Password, "", &ok);
    if (ok && password == "2137") {
        QDate selected = ui->calendarWidget->selectedDate();
        QTextCharFormat format;
        format.setBackground(QColor("#ADD8E6")); // light blue
        format.setFontWeight(QFont::Bold);
        ui->calendarWidget->setDateTextFormat(selected, format);
        QMessageBox::information(this, "Zatwierdzono", "Dzień oznaczony jako wolny.");
    } else if (ok) {
        QMessageBox::warning(this, "Błąd", "Niepoprawne hasło.");
    }
}
// Aktualizacja widoku zadań
void MainWindow::updateTaskList(const QDate &date) {
    ui->taskListWidget->clear();

    if (!tasks.contains(date)) return;

    for (const Task &task : tasks[date]) {
        ui->taskListWidget->addItem(task.toString());
    }
}
// Kontrola wykonalności zadania
void MainWindow::checkDeadlines() {
    QDateTime now = QDateTime::currentDateTime();
    for (auto date : tasks.keys()) {
        for (Task &task : tasks[date]) {
            if (!task.isDone() && !task.isOverdue()) {
                QDateTime now = QDateTime::currentDateTime();
                QDateTime deadline = task.getDeadline();

                if (now >= deadline) {
                    QMessageBox::StandardButton reply = QMessageBox::question(
                        this,
                        "Zadanie po terminie",
                        QString("Zadanie \"%1\" miało być wykonane do %2.\nCzy zostało wykonane?")
                            .arg(task.getText())
                            .arg(deadline.toString("dd.MM.yyyy hh:mm")),
                        QMessageBox::Yes | QMessageBox::No
                        );

                    if (reply == QMessageBox::Yes) {
                        bool authenticated = false;
                        int attempts = 0;

                        while (attempts < 3 && !authenticated) {
                            bool ok;
                            QString password = QInputDialog::getText(this, "Weryfikacja",
                                                                     QString("Podaj hasło administratora (próba %1 z 3):").arg(attempts + 1),
                                                                     QLineEdit::Password, "", &ok);
                            if (!ok) break;  // użytkownik anulował

                            if (password == "1108") {
                                authenticated = true;
                                task.setDone(true);
                                break;
                            } else {
                                ++attempts;
                                if (attempts == 3) {
                                    QMessageBox::warning(this, "Błąd", "3 nieudane próby. Zadanie oznaczone jako ❌.");
                                    task.setOverdue(true);
                                } else {
                                    QMessageBox::warning(this, "Błąd", "Niepoprawne hasło.");
                                }
                            }
                        }
                    } else if (reply == QMessageBox::No) {
                        task.setOverdue(true);
                    }

                    updateTaskList(date);
                }

        }
    }
    }
}

