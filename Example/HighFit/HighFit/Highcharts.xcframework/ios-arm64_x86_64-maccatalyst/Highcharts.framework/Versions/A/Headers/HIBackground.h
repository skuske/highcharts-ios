/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
An array of background items for the pane.

**Try it**

* [Speedometer gauge with multiple backgrounds](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-speedometer/)
*/
@interface HIBackground: HIChartsJSONSerializable

/**
The pane background border color.

**Defaults to** `#cccccc`.
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
The outer radius of the circular pane background. Can be either numeric (pixels) or a percentage string.

**Defaults to** `105%`.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ outerRadius;
/**
The border radius of the pane background when the shape is `arc`. Can be a number (pixels) or a percentage string.

**Try it**

* [Circular gauge and pane with equal border radius](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-solidgauge/pane-borderradius)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ borderRadius;
/**
The inner radius of the pane background. Can be either numeric (pixels) or a percentage string.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ innerRadius;
/**
The class name for this background.

**Try it**

* [Panes styled by CSS](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/pane/)
*/
@property(nonatomic, readwrite) NSString *className;
/**
The shape of the pane background. When `solid`, the background is circular. When `arc`, the background extends only from the min to the max of the value axis.

**Defaults to** `circle`.
*/
@property(nonatomic, readwrite) NSString *shape;
/**
The pixel border width of the pane background.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
The background color or gradient for the pane.

**Defaults to** `{ linearGradient: { x1: 0, y1: 0, x2: 0, y2: 1 }, stops: [[0, #ffffff], [1, #e6e6e6]] }`.
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;

-(NSDictionary *)getParams;

@end
