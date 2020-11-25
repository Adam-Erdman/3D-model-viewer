#include "PrismObjWindow.h"
#include "RecPrismBox.h"
#include <QPushButton>
#include <QSlider>
#include <QLayout>
#include <QFrame>
#include <QMenuBar>
#include <QMenu>
#include <QApplication>


PrismObjWindow::PrismObjWindow(QWidget *parent)
    : QWidget(parent)
{
    // Instantiate menu
    QMenu *qMenu = new QMenu(this);
    qMenu->addAction(tr("Exit"), qApp, &QApplication::quit);

    // Include menu bar
    QMenuBar *menuBar = new QMenuBar(this);
    menuBar->addMenu(qMenu)->setText(tr("&File"));

    //Include frame
    QFrame *qFrame = new QFrame(this);
    qFrame->setFrameStyle(QFrame::Sunken | QFrame::Panel);
    qFrame->setLineWidth(2);

    // Create rectangle prism object
    RecPrismBox *prBox = new RecPrismBox(qFrame, "RectanglePrismBox");

    // Create slider for color change
    QSlider *colorSlider = new QSlider(Qt::Horizontal, this);
    colorSlider->setMinimum(0);
    colorSlider->setMaximum(360);
    colorSlider->setPageStep(20);
    colorSlider->setTickPosition(QSlider::TicksBelow);
    connect(colorSlider, &QSlider::valueChanged, prBox, &RecPrismBox::makeXRotateAndChangeColor);

    QSlider *actualColorSlider = new QSlider(Qt::Horizontal, this);
    //actualColorSlider->setMinimum(0);
    actualColorSlider->setMaximum(360);
    actualColorSlider->setPageStep(20);
    actualColorSlider->setTickPosition(QSlider::TicksBelow);
    connect(actualColorSlider, &QSlider::valueChanged, prBox, &RecPrismBox::ChangeColor);

    //Create slider for **TBD
    QSlider *slider2 = new QSlider(Qt::Horizontal, this);
    slider2->setMaximum(360);
    slider2->setPageStep(20);
    slider2->setTickPosition(QSlider::TicksBelow);
    connect(slider2, &QSlider::valueChanged, prBox, &RecPrismBox::makeYRotateAndLightChange);

    //Create slider for zoom
    QSlider *zoom = new QSlider(Qt::Horizontal, this);
    zoom->setMaximum(360);
    zoom->setPageStep(20);
    zoom->setTickPosition(QSlider::TicksBelow);
    connect(zoom, &QSlider::valueChanged, prBox, &RecPrismBox::makeZoomInZoomOut);


    // place sliders in layout (horizontal)
    QHBoxLayout *horzBoxLyt = new QHBoxLayout(this);

    // place sliders in layout (vertical)
    QVBoxLayout *vertBoxLyt = new QVBoxLayout();
    vertBoxLyt->addWidget(colorSlider);
    vertBoxLyt->addWidget(slider2);
    vertBoxLyt->addWidget(zoom);
    vertBoxLyt->addWidget(actualColorSlider);

    // Layout for frame
    QHBoxLayout *frameLyt = new QHBoxLayout(qFrame);
    frameLyt->setMargin(0);
    frameLyt->addWidget(prBox, 1);

    horzBoxLyt->setMenuBar(qMenu);
    horzBoxLyt->addLayout(vertBoxLyt);
    horzBoxLyt->addWidget(qFrame, 1);
}
