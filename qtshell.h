#ifndef QTSHELL_H
#define QTSHELL_H

#include "console.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QtShell; }
QT_END_NAMESPACE

class QtShell : public QMainWindow
{
    Q_OBJECT

public:
    QtShell(QWidget *parent = nullptr);
    ~QtShell();

private:
    Ui::QtShell *ui;
    Console *console;
};
#endif // QTSHELL_H
