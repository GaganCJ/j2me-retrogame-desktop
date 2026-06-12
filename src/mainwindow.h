#pragma once

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QDebug>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    // Capture low-level desktop keyboard intercepts smoothly
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    QOpenGLWidget *m_gameCanvas;
    void sendKeyToEngine(int legacyKeyCode, bool isPressed);
};