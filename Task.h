#ifndef TASK_H
#define TASK_H
#include <QString>
#include <QDateTime>
class Task{
public:
    Task(const QString &text = "", const QDateTime &deadline = QDateTime::currentDateTime(), bool done = false);

    QString getText() const;
    void setText(const QString &text);

    QDateTime getDeadline() const;
    void setDeadline(const QDateTime &deadline);

    bool isDone() const;
    void setDone(bool done);

    QString toString() const;
    void setOverdue(bool overdue) { m_overdue = overdue; }
    bool isOverdue() const { return m_overdue; }
private:
    QString m_text;
    QDateTime m_deadline;
    bool m_done;
    bool m_overdue = false;
};
#endif // TASK_H
