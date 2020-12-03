#include "PrismObjWindow.h"
#include "RecPrismBox.h"
#include <QPushButton>
#include <QSlider>
#include <QLayout>
#include <QFrame>
#include <QMenuBar>
#include <QMenu>
#include <QApplication>
#include <QLabel>
#include <QRadioButton>


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

    // Create slider for X axis rotation
    QSlider *sliderXAxis = new QSlider(Qt::Horizontal, this);
    sliderXAxis->setMinimum(0);
    sliderXAxis->setMaximum(360);
    sliderXAxis->setPageStep(20);
    sliderXAxis->setTickPosition(QSlider::TicksBelow);
    connect(sliderXAxis, &QSlider::valueChanged, prBox, &RecPrismBox::makeXRotate);

    QSlider *actualColorSlider = new QSlider(Qt::Horizontal, this);
    //actualColorSlider->setMinimum(0);
    actualColorSlider->setMaximum(256);
    actualColorSlider->setPageStep(16);
    actualColorSlider->setTickPosition(QSlider::TicksBelow);
    connect(actualColorSlider, &QSlider::valueChanged, prBox, &RecPrismBox::ChangeColor);

    // Create slider for Z axis rotation
    QSlider *sliderZAxis = new QSlider(Qt::Horizontal, this);
    sliderZAxis->setMinimum(0);
    sliderZAxis->setMaximum(360);
    sliderZAxis->setPageStep(20);
    sliderZAxis->setTickPosition(QSlider::TicksBelow);
    connect(sliderZAxis, &QSlider::valueChanged, prBox, &RecPrismBox::makeZRotate);


    //Create slider for **TBD
    QSlider *sliderYAxis = new QSlider(Qt::Horizontal, this);
    sliderYAxis->setMaximum(360);
    sliderYAxis->setPageStep(20);
    sliderYAxis->setTickPosition(QSlider::TicksBelow);
    connect(sliderYAxis, &QSlider::valueChanged, prBox, &RecPrismBox::makeYRotate);

    //Create slider for zoom
    QSlider *zoom = new QSlider(Qt::Horizontal, this);
    zoom->setMaximum(400);
    zoom->setMinimum(100);
    zoom->setPageStep(20);
    zoom->setTickPosition(QSlider::TicksBelow);
    connect(zoom, &QSlider::valueChanged, prBox, &RecPrismBox::makeZoomInZoomOut);

    //Create slider for shader
//    QSlider *shader = new QSlider(Qt::Horizontal, this);
//    shader->setMinimum(0);
//    shader->setMaximum(15);
//    shader->setPageStep(1);
//    shader->setTickPosition(QSlider::TicksBelow);
//    connect(shader, &QSlider::valueChanged, prBox, &RecPrismBox::shader);

    QLabel *labelX = new QLabel(this);
    labelX->setText("X Axis");

    QLabel *labelY = new QLabel(this);
    labelY->setText("Y Axis");

    QLabel *labelZ = new QLabel(this);
    labelZ->setText("Z Axis");

    QLabel *label3 = new QLabel(this);
    label3->setText("Zoom in/out");

    QLabel *label4 = new QLabel(this);
    label4->setText("Color");

//    QLabel *label5 = new QLabel(this);
//    label5->setText("Shader");

    QRadioButton *button1 = new QRadioButton("Box", this);
    connect(button1, &QRadioButton::clicked, prBox, &RecPrismBox::BoxRadio);
    QRadioButton *button2 = new QRadioButton("Pyramid", this);
    connect(button2, &QRadioButton::clicked, prBox, &RecPrismBox::PyramidRadio);
    QRadioButton *button3 = new QRadioButton("Prism", this);
    connect(button3, &QRadioButton::clicked, prBox, &RecPrismBox::ConeRadio);


    // place sliders in layout (horizontal)
    QHBoxLayout *horzBoxLyt = new QHBoxLayout(this);

    // place sliders in layout (vertical)
    QVBoxLayout *vertBoxLyt = new QVBoxLayout();
    vertBoxLyt->setContentsMargins(0,20,0,0);
    vertBoxLyt->addWidget(labelX);
    vertBoxLyt->addWidget(sliderXAxis);
    vertBoxLyt->addWidget(labelY);
    vertBoxLyt->addWidget(sliderYAxis);
    vertBoxLyt->addWidget(labelZ);
    vertBoxLyt->addWidget(sliderZAxis);
    vertBoxLyt->addWidget(label3);
    vertBoxLyt->addWidget(zoom);
    vertBoxLyt->addWidget(label4);
    vertBoxLyt->addWidget(actualColorSlider);
//    vertBoxLyt->addWidget(label5);
//    vertBoxLyt->addWidget(shader);
    vertBoxLyt->addWidget(button1);
    vertBoxLyt->addWidget(button2);
    vertBoxLyt->addWidget(button3);

    // Layout for frame
    QHBoxLayout *frameLyt = new QHBoxLayout(qFrame);
    frameLyt->setMargin(0);
    frameLyt->addWidget(prBox, 1);

    horzBoxLyt->setMenuBar(qMenu);
    horzBoxLyt->addLayout(vertBoxLyt);
    horzBoxLyt->addWidget(qFrame, 1);
}
