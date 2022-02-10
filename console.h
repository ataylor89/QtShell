#ifndef CONSOLE_H
#define CONSOLE_H

#include <QTextEdit>
#include <QKeyEvent>
#include <QProcess>

class Console : public QTextEdit
{
public:
    Console();

protected:
    void keyPressEvent(QKeyEvent *keyEvent);

private slots:
    void setPrefix(QString prefix);
    QString getPrefix();
    void read();

private:
    QProcess *interpreter;
    QString prefix;
};

#endif // CONSOLE_H
