#ifndef ELEMENTINFODIALOG_H
#define ELEMENTINFODIALOG_H

#include "element.h"

#include <QDialog>
/*
 * Dialog box shown for Element Info
 */
namespace Ui {
class ElementInfoDialog;
}

class ElementInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ElementInfoDialog(Element elem, QWidget *parent = 0);
    ~ElementInfoDialog();

private:
    Ui::ElementInfoDialog *ui;
    Element element;

    void setupLabels();
};

#endif // ELEMENTINFODIALOG_H
