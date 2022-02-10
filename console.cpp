#include "console.h"

Console::Console()
{
    setPrefix("& ");
    setText(prefix);
    moveCursor(QTextCursor::End);
}

void Console::runCommand(QString command)
{
    interpreter = new QProcess(this);
    interpreter->start("/bin/zsh", QStringList() << "-c" << command);
    interpreter->waitForFinished();
    QString output = QString(interpreter->readAll());
    append(output);
    delete interpreter;
}

void Console::keyPressEvent(QKeyEvent *keyEvent)
{
    if (keyEvent->key() == Qt::Key_Return)
    {
        QString text = toPlainText();
        int startPos = text.lastIndexOf(prefix) + prefix.length();
        QString command = text.mid(startPos);
        runCommand(command);
        append(prefix);
        moveCursor(QTextCursor::End);
    }
    else
    {
        QTextEdit::keyPressEvent(keyEvent);
    }
}

void Console::setPrefix(QString prefix)
{
    this->prefix = prefix;
}

QString Console::getPrefix()
{
    return prefix;
}
