#include <QOpenGLWidget>
#include <QOpenGLFunctions_1_1>
//#include <QAxBindable>

class RecPrismBox : public QOpenGLWidget,
              public QOpenGLFunctions_1_1
{
    Q_OBJECT


public:
    explicit RecPrismBox(QWidget *parent, const char *name = nullptr);
    virtual ~RecPrismBox();


public slots:
    void                makeXRotateAndChangeColor(int degrees);
    void                makeYRotateAndLightChange(int degrees);
    void                makeZoomInZoomOut(int degrees);
    void                ChangeColor(int degrees);
    virtual GLuint      makeObject();

protected:
    void                initializeGL() override;
    void                paintGL() override;
    void                resizeGL(int w, int h) override;


private:
    GLuint  prism_object = 0;
    GLdouble colorFactor = 0;
    GLdouble slider2Factor = 0;
    GLdouble zoomFactor = 0;
    GLdouble scaleFactor = 1.00;
};

