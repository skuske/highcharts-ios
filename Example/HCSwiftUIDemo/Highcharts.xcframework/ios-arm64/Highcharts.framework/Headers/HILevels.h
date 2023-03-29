/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIColorVariation.h"
#import "HIDataLabels.h"
#import "HIStates.h"
#import "HIColor.h"


/**
Set options on specific levels. Takes precedence over series options, but not point options.

**Try it**

* [Treegraph chart with level options applied](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-treegraph/level-options)
*/
@interface HILevels: HIChartsJSONSerializable

/**
Set collapsed status for nodes level-wise.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *collapsed;
/**
Can set a `borderColor` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
Determines whether the chart should receive one color per point based on this level.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
Can set a `colorVariation` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) HIColorVariation *colorVariation;
/**
Can set a `levelSize` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) id levelSize;
/**
Can set a `borderDashStyle` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) NSString *borderDashStyle;
/**
Decides which level takes effect from the options set in the levels object.

**Try it**

* [Sunburst chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst)
*/
@property(nonatomic, readwrite) NSNumber *level;
/**
Can set a `color` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Can set `dataLabels` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) HIDataLabels *dataLabels;
/**
Can set a `borderWidth` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
Can set the layoutAlgorithm option on a specific level.

**Accepted values:** `["sliceAndDice", "stripes", "squarified", "strip"]`.
*/
@property(nonatomic, readwrite) NSString *layoutAlgorithm;
/**
Can set the layoutStartingDirection option on a specific level.

**Accepted values:** `["vertical", "horizontal"]`.
*/
@property(nonatomic, readwrite) NSString *layoutStartingDirection;
/**
Can set `states` on all nodes and points which lay on the same level.
*/
@property(nonatomic, readwrite) HIStates *states;
/**
Can set `linkOpacity` on all points which lay on the same level.

**Defaults to** `0.5`.
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;

-(NSDictionary *)getParams;

@end
