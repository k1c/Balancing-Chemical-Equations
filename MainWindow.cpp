#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "element.h"
#include "periodictable.h"
#include "elementinfodialog.h"
#include "reaction.h"

#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupDropdownBoxes();
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::setupDropdownBoxes()
{
    for (int index = 0; index < Size; index++) {
        Element elem = table[index];
        QString name = QString::fromStdString(elem.getName());

        ui->dropdownElementOne->addItem(name);
        ui->dropdownElementTwo->addItem(name);
    }
}

void MainWindow::on_dropdownElementOne_currentIndexChanged(int index)
{
        Element elem = table[index];
        elementOne = elem;
}

void MainWindow::on_dropdownElementTwo_currentIndexChanged(int index)
{
        Element elem = table[index];
        elementTwo = elem;
}

void MainWindow::showElementInfo()
{
    QString objectName = sender()->objectName();
    if(objectName == "buttonShowInfoOne") {
        ElementInfoDialog *infoDialog = new ElementInfoDialog(elementOne);
        infoDialog->open();
    } else if(objectName == "buttonShowInfoTwo") {
        ElementInfoDialog *infoDialog = new ElementInfoDialog(elementTwo);
        infoDialog->open();
    }
}

void MainWindow::on_buttonShowInfoOne_clicked()
{
    showElementInfo();
}

void MainWindow::on_buttonShowInfoTwo_clicked()
{
    showElementInfo();
}

void MainWindow::setElementTwoAmount(double value)
{
    elementTwoAmount = value;
}

void MainWindow::setElementOneAmount(double value)
{
    elementOneAmount = value;
}

double MainWindow::getElementTwoAmount() const
{
    return elementTwoAmount;
}

double MainWindow::getElementOneAmount() const
{
    return elementOneAmount;
}

void MainWindow::on_spinBoxElementOne_valueChanged(double amount)
{
    elementOneAmount = amount;
}

void MainWindow::on_doubleSpinBox_2_valueChanged(double amount)
{
    elementTwoAmount = amount;
}


void MainWindow::on_buttonCombined_clicked()
{
    Reaction reaction;
    reaction.make_elements(elementOne.getAtomicNumber(), elementOneAmount, elementTwo.getAtomicNumber(), elementTwoAmount);
    reaction.make_compound();

    ui->labelResult->setText(QString::fromStdString(reaction.getEquation().toString()));
}
