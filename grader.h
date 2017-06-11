#ifndef GRADER_H
#define GRADER_H

#include <QMainWindow>
#include <vector>

namespace Ui {
class grader;
}

class grader : public QMainWindow
{
    Q_OBJECT

public:
    explicit grader(QWidget *parent = 0);
    ~grader();

public slots:
    double compute_overall(int unused);
    void update_overall(int);

private:
    Ui::grader *ui;
    std::vector<int> scores;
};

#endif
