#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "periodictable.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    double getElementOneAmount() const;

    double getElementTwoAmount() const;

    void setElementOneAmount(double value);

    void setElementTwoAmount(double value);

public slots:
    // Called when the dropdown box index is changed. Index corresponds to the item in the periodic table
    void on_dropdownElementOne_currentIndexChanged(int index);
    void on_dropdownElementTwo_currentIndexChanged(int index);
    // Show element info, use the ID of the button that was clicked to get the right element
    void showElementInfo();
private slots:
    // Called when the show info buttons are clicked. Shows the info from the periodic table for the selected elements
    void on_buttonShowInfoOne_clicked();
    void on_buttonShowInfoTwo_clicked();
    // Called when the value is changed for the amount of the element in moles
    void on_spinBoxElementOne_valueChanged(double arg1);
    void on_doubleSpinBox_2_valueChanged(double arg1);
    // Called when the combine button is clicked. Uses the other input along with the Reaction class to display the final resulting equation
    void on_buttonCombined_clicked();

private:
    Ui::MainWindow *ui;
    PeriodicTable table;

    // ELements used in the reaction
    Element elementOne;
    // Amount in moles for the reaction
    double elementOneAmount;

    Element elementTwo;
    double elementTwoAmount;
    // Fill the dropdown menus with elements from the periodic table
    void setupDropdownBoxes();
};

#endif
