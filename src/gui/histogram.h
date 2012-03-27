#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_

#include <stdlib.h>
#include <qpen.h>
#include <qwt_plot_layout.h>
#include <qwt_legend.h>
#include <qwt_legend_item.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_histogram.h>
#include <qwt_column_symbol.h>
#include <qwt_series_data.h>

class Histogram: public QwtPlotHistogram
{
public:
    Histogram( const QString &, const QColor & );

    void setColor( const QColor & );
    void setValues( uint numValues, const double * );
};

#endif /* HISTOGRAM_H_ */
