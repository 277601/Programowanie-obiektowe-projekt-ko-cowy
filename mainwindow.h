#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QListWidgetItem>
#include "Task.h"
#include <QVector>
#include <QMap>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_removeButton_clicked();
    void markTaskAsDone();
    void markDayAsFree();
    void checkDeadlines();
    void openSettingsDialog();


private:
    Ui::MainWindow *ui;
    QMap<QDate, QList<Task>> tasks;
    void updateTaskList(const QDate &date);
    QTimer *deadlineTimer;
};

#endif // MAINWINDOW_H
