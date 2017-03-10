#include "elementinfodialog.h"
#include "ui_elementinfodialog.h"

ElementInfoDialog::ElementInfoDialog(Element elem, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ElementInfoDialog)
{
    ui->setupUi(this);
    element = elem;
    setupLabels();
}

ElementInfoDialog::~ElementInfoDialog()
{
    delete ui;
}

void ElementInfoDialog::setupLabels()
{
    QString name = "Element Name: " + QString::fromStdString(element.getName());
    QString abbrev = "Abbreviation: " + QString::fromStdString(element.get_abbreviation());
    QString number = "Atomic Number: " + QString::number(element.getAtomicNumber());
    QString mass = "Atomic Mass: " + QString::number(element.get_atomic_mass()) + " amu";
    QString charge = "Charge: " + QString::number(element.getCharge());

    ui->labelName->setText(name);
    ui->labelAbbreviation->setText(abbrev);
    ui->labelAtomicNumber->setText(number);
    ui->labelAtomicMass->setText(mass);
    ui->labelCharge->setText(charge);
}
