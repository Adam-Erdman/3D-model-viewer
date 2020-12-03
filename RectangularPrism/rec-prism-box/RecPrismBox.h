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
    void                makeXRotate(int degrees);
    void                makeYRotate(int degrees);
    void                makeZRotate(int degrees);
    void                shader(int degrees);

    void                makeZoomInZoomOut(int degrees);
    void                ChangeColor(int degrees);
    void                BoxRadio(bool clicked);
    void                PyramidRadio(bool clicked);
    void                ConeRadio(bool clicked);
    virtual GLuint      makeObject();
    virtual GLuint      makeObjectPyramid();
    virtual GLuint      makeObjectPrism();

protected:
    void                initializeGL() override;
    void                paintGL() override;
    void                resizeGL(int w, int h) override;


private:
    GLuint  prism_object = 0;
    GLdouble sliderxFactor = 0;
    GLdouble slideryFactor = 0;
    GLdouble sliderzFactor = 0;
    GLdouble zoomFactor = 0;
    GLdouble shaderFactor =0;
    GLdouble scaleFactor = 1.00;


};

