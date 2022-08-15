#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include <QDialog>
namespace Ui {class CCalculator;};

class QStringListModel;

class CCalculator : public QDialog
{
    Q_OBJECT

public:
    CCalculator(QWidget *parent = 0);
    ~CCalculator();
    void keyPressEvent( QKeyEvent * event );

    int numValues() const;
    bool eventFilter(QObject *obj, QEvent *event);
    
public slots:
    void btn0Clicked();
    void btn1Clicked();
    void btn2Clicked();
    void btn3Clicked();
    void btn4Clicked();
    void btn5Clicked();
    void btn6Clicked();
    void btn7Clicked();
    void btn8Clicked();
    void btn9Clicked();
    void btnPeriodClicked();
    void btnEnterClicked();
    void btnDeleteClicked();
    void btnBSClicked();  

    void btnModClicked();
    void btnPlusClicked();
    void btnMinusClicked();
    void btnMultClicked();
    void btnDivClicked();
    void btnCAClicked();
    void btnAverageClicked();
    void btnNegateClicked();
    void btnSqrtClicked();
    void btnSquareClicked();
    void btnQuadClicked();

    void btnPowClicked();
    void btnCubedClicked();
    void btnTenPowClicked();
    void btnFactClicked();

    void btnCubeRootClicked();
    void btnRootPowClicked();
    void btnPiClicked();

    void btnLog10Clicked();
    void btnLog2Clicked();
    void btn2PowClicked();

    void btnCAreaClicked();
    void btnCircClicked();
    void btnRAreaClicked();
    void btnPeriClicked();
    void btnRatioClicked();
    void btnVolCylClicked();
    void btnVolCubeClicked();

private:
    void errorNumVals( int numValues ) const;
    void errorInvalidValue( const QString & numValues ) const;
    double getLastValue( bool popLast );
    void addValue( char value );
    void setLastValue( double value );

    Ui::CCalculator *ui;
    QStringListModel * fModel;
};

#endif // _ALCULATOR_H
