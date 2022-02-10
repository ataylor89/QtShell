#include "qtshell.h"
#include "ui_qtshell.h"

QtShell::QtShell(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtShell)
{
    ui->setupUi(this);
    console = new Console();
    this->setCentralWidget(console);
}

QtShell::~QtShell()
{
    delete ui;
}

