/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIFocusBorder.h"
#import "HISeriesNavigation.h"


/**
Options for keyboard navigation for the legend.
*/
@interface HIKeyboardNavigation: HIChartsJSONSerializable

/**
Enable keyboard navigation for the legend.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Whether or not to wrap around when reaching the end of arrow-key navigation for an element in the chart.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *wrapAround;
/**
Options for the focus border drawn around elements while navigating through them.

**Try it**

* [Custom focus ring](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/accessibility/custom-focus)
*/
@property(nonatomic, readwrite) HIFocusBorder *focusBorder;
/**
Order of tab navigation in the chart. Determines which elements are tabbed to first. Available elements are: `series`, `zoom`, `rangeSelector`, `navigator`, `chartMenu`, `legend` and `container`. In addition, any custom components can be added here. Adding `container` first in order will make the keyboard focus stop on the chart container first, requiring the user to tab again to enter the chart.
*/
@property(nonatomic, readwrite) NSArray<NSString *> *order;
/**
Options for the keyboard navigation of data points and series.
*/
@property(nonatomic, readwrite) HISeriesNavigation *seriesNavigation;

-(NSDictionary *)getParams;

@end
