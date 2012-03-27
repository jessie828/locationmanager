#include "plot.h"

Plot::Plot(QWidget *parent) : QwtPlot( parent )
{
    setTitle( "Watching TV during a weekend" );

    setCanvasBackground( QColor( Qt::gray ) );
    plotLayout()->setAlignCanvasToScales( true );

    setAxisTitle( QwtPlot::yLeft, "Number of People" );
    setAxisTitle( QwtPlot::xBottom, "Number of Hours" );

    QwtLegend *legend = new QwtLegend;
    legend->setItemMode( QwtLegend::CheckableItem );
    insertLegend( legend, QwtPlot::RightLegend );

    populate();

    connect( this, SIGNAL( legendChecked( QwtPlotItem *, bool ) ),
        SLOT( showItem( QwtPlotItem *, bool ) ) );

    replot(); // creating the legend items

    QwtPlotItemList items = itemList( QwtPlotItem::Rtti_PlotHistogram );
    for ( int i = 0; i < items.size(); i++ )
    {
        if ( i == 0 )
        {
            QwtLegendItem *legendItem =
                qobject_cast<QwtLegendItem *>( legend->find( items[i] ) );
            if ( legendItem )
                legendItem->setChecked( true );

            items[i]->setVisible( true );
        }
        else
            items[i]->setVisible( false );
    }

    setAutoReplot( true );

}

Plot::~Plot()
{

}


void Plot::populate()
{
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableX( false );
    grid->enableY( true );
    grid->enableXMin( false );
    grid->enableYMin( false );
    grid->setMajPen( QPen( Qt::black, 0, Qt::DotLine ) );
    grid->attach( this );

    const double juneValues[] = { 7, 19, 24, 32, 10, 5, 3 };
    const double novemberValues[] = { 4, 15, 22, 34, 13, 8, 4 };

    Histogram *histogramJune = new Histogram( "Summer", Qt::red );
    histogramJune->setValues(
        sizeof( juneValues ) / sizeof( double ), juneValues );
    histogramJune->attach( this );

    Histogram *histogramNovember = new Histogram( "Winter", Qt::blue );
    histogramNovember->setValues(
        sizeof( novemberValues ) / sizeof( double ), novemberValues );
    histogramNovember->attach( this );
}



void Plot::showItem( QwtPlotItem *item, bool on )
{
    item->setVisible( on );
}


