#ifndef MODELVIEWER_H
#define MODELVIEWER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ModelViewer; }
QT_END_NAMESPACE

class ModelViewer : public QMainWindow
{
    Q_OBJECT

public:
    ModelViewer(QWidget *parent = nullptr);
    ~ModelViewer();

private:
    Ui::ModelViewer *ui;
};
#endif // MODELVIEWER_H
