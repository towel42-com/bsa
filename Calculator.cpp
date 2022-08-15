#include "Calculator.h"
#include "ui_Calculator.h"

#include <QStringListModel>
#include <QKeyEvent>
#include <QMessageBox>
#include <QHeaderView>
#include <QDebug>
#include <cmath>
#include <QApplication>

bool CCalculator::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->values) 
    {
        if (event->type() == QEvent::KeyPress) 
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            keyPressEvent( keyEvent );
            return true;
        } 
        else 
        {
            return false;
        }
    } else 
    {
        // pass the event on to the parent class
        return QDialog::eventFilter(obj, event);
    }
}

CCalculator::CCalculator(QWidget *parent)
    : QDialog(parent)
{
	ui = new Ui::CCalculator();
	ui->setupUi(this);

    fModel = new QStringListModel( this );
    ui->values->setModel( fModel );

    connect( ui->btn_0, SIGNAL( clicked() ), this, SLOT( btn0Clicked() ) );
    connect( ui->btn_1, SIGNAL( clicked() ), this, SLOT( btn1Clicked() ) );
    connect( ui->btn_2, SIGNAL( clicked() ), this, SLOT( btn2Clicked() ) );
    connect( ui->btn_3, SIGNAL( clicked() ), this, SLOT( btn3Clicked() ) );
    connect( ui->btn_4, SIGNAL( clicked() ), this, SLOT( btn4Clicked() ) );
    connect( ui->btn_5, SIGNAL( clicked() ), this, SLOT( btn5Clicked() ) );
    connect( ui->btn_6, SIGNAL( clicked() ), this, SLOT( btn6Clicked() ) );
    connect( ui->btn_7, SIGNAL( clicked() ), this, SLOT( btn7Clicked() ) );
    connect( ui->btn_8, SIGNAL( clicked() ), this, SLOT( btn8Clicked() ) );
    connect( ui->btn_9, SIGNAL( clicked() ), this, SLOT( btn9Clicked() ) );
    connect( ui->btn_enter, SIGNAL( clicked() ), this, SLOT( btnEnterClicked() ) );
    connect( ui->btn_period, SIGNAL( clicked() ), this, SLOT( btnPeriodClicked() ) );
    connect( ui->btn_plus, SIGNAL( clicked() ), this, SLOT( btnPlusClicked() ) );
    connect( ui->btn_mod, SIGNAL( clicked() ), this, SLOT( btnModClicked() ) );

    connect( ui->btnMinus, SIGNAL( clicked() ), this, SLOT( btnMinusClicked() ) );

    connect( ui->btn_CA, SIGNAL( clicked() ), this, SLOT( btnCAClicked() ) );
    connect( ui->btn_Average, SIGNAL( clicked() ), this, SLOT( btnAverageClicked() ) );

    connect( ui->btn_mult, SIGNAL( clicked() ), this, SLOT( btnMultClicked() ) );
    connect( ui->btn_div, SIGNAL( clicked() ), this, SLOT( btnDivClicked() ) );
    connect( ui->btn_negate, SIGNAL( clicked() ), this, SLOT( btnNegateClicked() ) );

    connect( ui->btn_sqrt, SIGNAL( clicked() ), this, SLOT( btnSqrtClicked() ) );
    connect( ui->btn_square, SIGNAL( clicked() ), this, SLOT( btnSquareClicked() ) );
    connect( ui->btn_quad, SIGNAL( clicked() ), this, SLOT( btnQuadClicked() ) );

    connect( ui->btn_pow, SIGNAL( clicked() ), this, SLOT( btnPowClicked() ) );
    connect( ui->btn_cubed, SIGNAL( clicked() ), this, SLOT( btnCubedClicked() ) );
    connect( ui->btn_tenpow, SIGNAL( clicked() ), this, SLOT( btnTenPowClicked() ) );
    connect( ui->btn_fact, SIGNAL( clicked() ), this, SLOT( btnFactClicked() ) );
    connect( ui->btn_cuberoot, SIGNAL( clicked() ), this, SLOT( btnCubeRootClicked() ) );
    connect( ui->btn_rootpow, SIGNAL( clicked() ), this, SLOT( btnRootPowClicked() ) );
    connect( ui->btn_pi, SIGNAL( clicked() ), this, SLOT( btnPiClicked() ) );

    connect( ui->btn_log10, SIGNAL( clicked() ), this, SLOT( btnLog10Clicked() ) );
    connect( ui->btn_log2, SIGNAL( clicked() ), this, SLOT( btnLog2Clicked() ) );
    connect( ui->btn_2pow, SIGNAL( clicked() ), this, SLOT( btn2PowClicked() ) );
    
    connect( ui->btn_carea, SIGNAL( clicked() ), this, SLOT( btnCAreaClicked() ) );
    connect( ui->btn_circ, SIGNAL( clicked() ), this, SLOT( btnCircClicked() ) );

    connect( ui->btn_rarea, SIGNAL( clicked() ), this, SLOT( btnRAreaClicked() ) );
    connect( ui->btn_peri, SIGNAL( clicked() ), this, SLOT( btnPeriClicked() ) );
    connect( ui->btn_ratio, SIGNAL( clicked() ), this, SLOT( btnRatioClicked() ) );

    connect( ui->btn_vcyl, SIGNAL( clicked() ), this, SLOT( btnVolCylClicked() ) );
    connect( ui->btn_volcube, SIGNAL( clicked() ), this, SLOT( btnVolCubeClicked() ) );

    ui->values->installEventFilter( this );
    setFocus( Qt::MouseFocusReason );
}

void CCalculator::keyPressEvent( QKeyEvent * event )
{
    Qt::KeyboardModifiers mods = QApplication::keyboardModifiers();

    switch (event->key()) 
    {
    case Qt::Key_Period:
        ui->btn_period->animateClick();
        break;
    case Qt::Key_0:
        ui->btn_0->animateClick();
        break;
    case Qt::Key_1:
        ui->btn_1->animateClick();
        break;
    case Qt::Key_2:
        ui->btn_2->animateClick();
        break;
    case Qt::Key_3:
        ui->btn_3->animateClick();
        break;
    case Qt::Key_4:
        ui->btn_4->animateClick();
        break;
    case Qt::Key_5:
        ui->btn_5->animateClick();
        break;
    case Qt::Key_6:
        ui->btn_6->animateClick();
        break;
    case Qt::Key_7:
        ui->btn_7->animateClick();
        break;
    case Qt::Key_8:
        ui->btn_8->animateClick();
        break;
    case Qt::Key_9:
        ui->btn_9->animateClick();
        break;
    case Qt::Key_Enter:
    case Qt::Key_Return:
        ui->btn_enter->animateClick();
        break;

    case Qt::Key_Backspace:
        btnBSClicked();  
        break;
    case Qt::Key_Delete:
        btnDeleteClicked();  
        break;
    case Qt::Key_Plus:
        ui->btn_plus->animateClick();
        break;
    case Qt::Key_Percent:
        ui->btn_mod->animateClick();
        break;
    case Qt::Key_Minus:
        ui->btnMinus->animateClick();
        break;
    case Qt::Key_Slash:
        ui->btn_div->animateClick();
        break;
    case Qt::Key_Asterisk:
        ui->btn_mult->animateClick();
        break;
    case Qt::Key_AsciiCircum:
        ui->btn_pow->animateClick();
        break;
    case Qt::Key_Exclam:
        ui->btn_fact->animateClick();
        break;
    case Qt::Key_A:
        if ( ( mods & Qt::ShiftModifier ) != 0 )
        {
            ui->btn_carea->animateClick();
        }
        else
            ui->btn_rarea->animateClick();

        break;
    case Qt::Key_C:
        ui->btn_circ->animateClick();
        break;
    case Qt::Key_P:
        ui->btn_peri->animateClick();
        break;
    default:
        qDebug() << event->key();
        QDialog::keyPressEvent(event);
    }
}

CCalculator::~CCalculator()
{
	delete ui;
}

void CCalculator::btn0Clicked()
{
    addValue( '0' );
}

void CCalculator::btn1Clicked()
{
    addValue( '1' );
}

void CCalculator::btn2Clicked()
{
    addValue( '2' );
}

void CCalculator::btn3Clicked()
{
    addValue( '3' );
}

void CCalculator::btn4Clicked()
{
    addValue( '4' );
}

void CCalculator::btn5Clicked()
{
    addValue( '5' );
}

void CCalculator::btn6Clicked()
{
    addValue( '6' );
}

void CCalculator::btn7Clicked()
{
    addValue( '7' );
}

void CCalculator::btn8Clicked()
{
    addValue( '8' );
}

void CCalculator::btn9Clicked()
{
    addValue( '9' );
}

void CCalculator::btnPeriodClicked()
{
    addValue( '.' );
}

double CCalculator::getLastValue( bool popLast )
{
    if ( fModel->rowCount() == 0 )
        return 0.0;

    QModelIndex mi = fModel->index( fModel->rowCount() - 1 );
    if ( mi.data().toString().isEmpty() )
    {
        if ( !popLast )
            return 0.0;
        fModel->removeRows( fModel->rowCount()-1, 1 );
        mi = fModel->index( fModel->rowCount() - 1 );
    }

    bool aOK = false;
    double currValue = mi.data().toDouble( &aOK );
    if ( !aOK )
    {
        if ( popLast )
            fModel->removeRows( fModel->rowCount()-1, 1 );
        return 0.0;
    }

    if ( popLast )
        fModel->removeRows( fModel->rowCount()-1, 1 );
    return currValue;
}

void CCalculator::btnEnterClicked()
{
    if ( numValues() == 0 )
        return;

    QModelIndex mi = fModel->index( fModel->rowCount() - 1 );
    QString currValue = fModel->data( mi, Qt::EditRole ).toString();
    if ( currValue.isEmpty() )
        return;

    fModel->insertRows( fModel->rowCount(), 1 );
}

void CCalculator::btnDeleteClicked()
{
    if ( numValues() == 0 )
        return;

    QModelIndex mi = fModel->index( fModel->rowCount() - 1 );
    fModel->setData( mi, "" ); 
}

void CCalculator::btnBSClicked()
{
    if ( numValues() == 0 )
        return;

    QModelIndex mi = fModel->index( fModel->rowCount() - 1 );
    QString currValue = fModel->data( mi, Qt::EditRole ).toString();
    if ( currValue.isEmpty() )
        return;
    currValue = currValue.left( currValue.length() - 1 );
    fModel->setData( mi , currValue );
}

void CCalculator::addValue( char value )
{
    QModelIndex mi;
    QString currValue;
    if ( fModel->rowCount() )
    {
        mi = fModel->index( fModel->rowCount() - 1 );
        currValue = fModel->data( mi, Qt::EditRole ).toString();
    }
    else
    {
        fModel->insertRows( fModel->rowCount(), 1 );
        mi = fModel->index( 0, 0 );
    }
    currValue += value;
    fModel->setData( mi, currValue ); 
}

void CCalculator::setLastValue( double value )
{
    QString newValue = QString::number( value );
    fModel->insertRows( fModel->rowCount(), 1 );
    QModelIndex mi = fModel->index( fModel->rowCount() - 1 );
    fModel->setData( mi, newValue );
}

int CCalculator::numValues() const
{
    return fModel->rowCount();
}

void CCalculator::errorNumVals( int numValues ) const
{
    QMessageBox::critical( NULL, QString( "Input error" ), QString( "This function requires %1 values" ).arg( numValues ) );
}

void CCalculator::errorInvalidValue( const QString & msg ) const
{
    QMessageBox::critical( NULL, QString( "Input error" ), msg );
}

void CCalculator::btnModClicked()
{
    if ( numValues() < 2 )
    {
        errorNumVals( 2 );
        return;
    }

    int val2 = getLastValue( true );
    int val1 = getLastValue( true );
    double newValue = val1 % val2;
    setLastValue( newValue );
}

void CCalculator::btnPlusClicked()
{
    if ( numValues() < 2 )
    {
        errorNumVals( 2 );
        return;
    }

    double val2 = getLastValue( true );
    double val1 = getLastValue( true );
    double newValue = val1 + val2;
    setLastValue( newValue );
}

void CCalculator::btnMinusClicked ()
{
    if ( numValues() < 2 )
    {
        errorNumVals( 2 );
        return;
    }
    double val2 = getLastValue( true ) ;
    double val1 = getLastValue ( true ) ;
    double newValue = val1 - val2 ;
    setLastValue (newValue) ;
}

void CCalculator::btnMultClicked()
{
    if ( numValues() < 2 )
    {
        errorNumVals( 2 );
        return;
    }
    double val2 = getLastValue( true ) ;
    double val1 = getLastValue ( true ) ;
    double newValue = val1 * val2 ;
    setLastValue( newValue );
}

void CCalculator::btnDivClicked()
{
    if ( numValues() < 2 )
    {
        errorNumVals( 2 );
        return;
    }
    double denom = getLastValue( false );
    if ( denom == 0.0 )
    {
        errorInvalidValue( "The denominator can not be zero" );
        return;
    }
    getLastValue(true);
    double numer = getLastValue(true);
    double newValue = numer/denom;
    setLastValue(newValue);

}

void CCalculator::btnCAClicked()
{
    fModel->setStringList( QStringList() );
}

void CCalculator::btnAverageClicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }

    int num= 0;
    double total = 0;
    while ( numValues() > 0)
    {
        num = num + 1;
        double curr = getLastValue ( true);
        total += curr;
    }
    double newValue = total / num;
    setLastValue ( newValue);
}

void CCalculator::btnNegateClicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }

    double val = getLastValue(true);
    double newVal = -1.0*val;
    
    setLastValue( newVal );
}

void CCalculator::btnSqrtClicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }

    double val = getLastValue(true);
    double newVal = sqrt( val );
    
    setLastValue( newVal );
}

void CCalculator::btnSquareClicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }

    double val = getLastValue(true);
    double newVal = val*val ;
    
    setLastValue( newVal );
}

void CCalculator::btnQuadClicked()
{
    if ( numValues() < 3 )
    {
        errorNumVals( 3 );
        return;
    }

    double valC = getLastValue(true);
    double valB = getLastValue(true);
    double valA = getLastValue(true);

    if ( valA == 0)
    {
        errorInvalidValue( "Value A cannot be Zero" );
        return;
    }

    double inner = ( valB * valB ) - 4*valA*valC;
    if ( inner < 0 )
    {
        errorInvalidValue( "B^2 - 4*A*C must be greater than or equal to 0" );
        return;
    }
    double root = sqrt ( inner );
    double newVal1 = ( -valB - root ) / 2* valA;
    double newVal2 = ( -valB + root ) / 2* valA;
    
    setLastValue( newVal1 );
    setLastValue( newVal2 );
}

void CCalculator::btnPowClicked()
{
    if ( numValues() < 2 )
    {
        errorNumVals( 2 );
        return;
    }

    double val2 = getLastValue( true );
    double val1 = getLastValue( true );

    double newValue = pow( val1, val2 );
   
    setLastValue(newValue);
}


void CCalculator::btnCubedClicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }

    double val1 = getLastValue( true );
    double newValue = pow( val1, 3 );
   
    setLastValue(newValue);
}

void CCalculator::btnTenPowClicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }

    double val1 = getLastValue( true );
    double newValue = pow( 10, val1 );
   
    setLastValue(newValue);
}

void CCalculator::btnFactClicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }

    double val1 = getLastValue( true );
    if( val1 <0)
    {
        errorInvalidValue( "value >0");
        return;
    }
    int decVal = floor( val1 );
    int retVal=1;
    while ( decVal > 0 )
    {
        retVal = retVal * decVal;
        decVal = decVal - 1;
    }

    setLastValue( retVal );
}

void CCalculator::btnCubeRootClicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }
    double val1 = getLastValue( true );
    double newValue = pow( val1, 1.0/3.0 );
   
    setLastValue(newValue);
}

void CCalculator::btnRootPowClicked()
{
    if ( numValues() < 2 )
    {
        errorNumVals( 2 );
        return;
    }
    double val2 = getLastValue( true );
    double val1 = getLastValue( true );

    double newValue = pow( val1, (1/val2) );
   
    setLastValue(newValue);
}

#define PI 3.1415926535897

void CCalculator::btnPiClicked()
{
    setLastValue( PI );
}

void CCalculator::btnLog10Clicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }

    double val = getLastValue( true );

    double newVal = log10( val );

    setLastValue( newVal );
}

double log2( double n )  
{ 
    double retVal = log( n );
    retVal = retVal / log( 2.0 );
    return retVal;
}

void CCalculator::btnLog2Clicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }

    double val = getLastValue( true );

    double newVal = log2( val );

    setLastValue( newVal );
}

void CCalculator::btn2PowClicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }

    double val = getLastValue( true );

    double newVal = pow( 2.0, val );

    setLastValue( newVal );
}



void CCalculator::btnCAreaClicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }

    double val = getLastValue( true );

    double newVal = PI*val*val;
        
    setLastValue( newVal );
}

void CCalculator::btnCircClicked()
{
    if ( numValues() < 1 )
    {
        errorNumVals( 1 );
        return;
    }

    double val = getLastValue( true );

    double newVal = 2*PI*val;
        
    setLastValue( newVal );
}

void CCalculator::btnRAreaClicked()
{
    if ( numValues() < 2 )
    {
        errorNumVals( 2 );
        return;
    }

    double val2 = getLastValue( true );
    double val1 = getLastValue( true );

    double newVal = val1*val2;
        
    setLastValue( newVal );
}

void CCalculator::btnPeriClicked()
{
    if ( numValues() < 2 )
    {
        errorNumVals( 2 );
        return;
    }

    double val2 = getLastValue( true );
    double val1 = getLastValue( true );

    double newVal = val1+val1+val2+val2;
        
    setLastValue( newVal );
}

void CCalculator::btnRatioClicked()
{
    if ( numValues() < 3 )
    {
        errorNumVals( 3 );
        return;
    }

    double val3 = getLastValue( true );
    double val2 = getLastValue( true );
    double val1 = getLastValue( true );

    if ( val3 == 0 )
    {
        errorInvalidValue( "val3 cannot be 0" );
        return;
    }

    if ( val2 == 0 )
    {
        errorInvalidValue( "val2 cannot be 0" );
        return;
    }

    double newVal = val1*val3/val2;
        
    setLastValue( newVal );
}

void CCalculator::btnVolCylClicked()
{
    if ( numValues() < 2 )
    {
        errorNumVals( 2 );
        return;
    }

    double height = getLastValue( true );
    double radius = getLastValue( true );

    double newVal = PI*radius*radius*height;
        
    setLastValue( newVal );
}

void CCalculator::btnVolCubeClicked()
{
    if ( numValues() < 3 )
    {
        errorNumVals( 3 );
        return;
    }

    double height = getLastValue(true);
    double width = getLastValue(true);
    double base = getLastValue(true);

    double newVal = base*height*width;
        
    setLastValue( newVal );
}
