/**
 * @license Highcharts JS v11.4.3 (2024-05-22)
 * @module highcharts/modules/xrange
 * @requires highcharts
 *
 * X-range series
 *
 * (c) 2010-2024 Torstein Honsi, Lars A. V. Cabrera
 *
 * License: www.highcharts.com/license
 */
'use strict';
import Highcharts from '../../Core/Globals.js';
import XRangeSeries from '../../Series/XRange/XRangeSeries.js';
const G = Highcharts;
XRangeSeries.compose(G.Axis);
export default Highcharts;