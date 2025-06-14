#include "Task.h"
Task::Task(const QString &text, const QDateTime &deadline, bool done)
    : m_text(text), m_deadline(deadline), m_done(done) {}

QString Task::getText() const {
    return m_text;
}

void Task::setText(const QString &text) {
    m_text = text;
}

QDateTime Task::getDeadline() const {
    return m_deadline;
}

void Task::setDeadline(const QDateTime &deadline) {
    m_deadline = deadline;
}

bool Task::isDone() const {
    return m_done;
}

void Task::setDone(bool done) {
    m_done = done;
}

QString Task::toString() const {
    QString status;
    if (m_done) {
        status = "✅";
    } else if (m_overdue) {
        status = "❌";
    } else {
        status = "🕒";
    }
    QString deadlineStr = m_deadline.toString("dd.MM.yyyy hh:mm");
    return QString("%1 [%2] %3").arg(status, deadlineStr, m_text);
}
