#include "console.h"

Console::Console()
{
    setPrefix("& ");
    setText(prefix);
    interpreter = new QProcess(this);
    connect(interpreter, SIGNAL(readyReadStandardOutput()), this, SLOT(read));
    interpreter->start("/bin/zsh", QStringList() << "");
}

void Console::keyPressEvent(QKeyEvent *keyEvent)
{
    if (keyEvent->key() == Qt::Key_Return)
    {
        append(prefix);
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

void Console::read()
{
    QByteArray bytes = interpreter->readAll();
    append(QString(bytes));
}
