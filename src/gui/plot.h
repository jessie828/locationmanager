#ifndef PLOT_H_
#define PLOT_H_

#include "histogram.h"

#include <qwt_plot.h>
#include <stdlib.h>
#include <qpen.h>
#include <qwt_plot_layout.h>
#include <qwt_legend.h>
#include <qwt_legend_item.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_histogram.h>
#include <qwt_column_symbol.h>
#include <qwt_series_data.h>

class Plot: public QwtPlot
{
    Q_OBJECT

public:
    Plot( QWidget * = NULL );
    virtual ~Plot();

private:
    void populate();

private Q_SLOTS:
    void showItem( QwtPlotItem *, bool on );
};



#endif /* PLOT_H_ */
