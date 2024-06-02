/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HINodes.h"
#import "HILevels.h"
#import "HIColor.h"


/**
 A `arcdiagram` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `arcdiagram` series are defined in `plotOptions.arcdiagram`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        arcdiagram: {
            // shared options for all arcdiagram series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'arcdiagram'
    }]
 });
 <pre>
 */
@interface HIArcdiagram: HISeries

/**
The radius of the link arc. If not set, series renders a semi-circle between the nodes, except when overflowing the edge of the plot area, in which case an arc touching the edge is rendered. If `linkRadius` is set, an arc extending to the given value is rendered.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSNumber *linkRadius;
/**
The offset of an arc diagram nodes column in relation to the `plotArea`. The offset equal to 50% places nodes in the center of a chart. By default the series is placed so that the biggest node is touching the bottom border of the `plotArea`.

**Defaults to** `'100%'`.
*/
@property(nonatomic, readwrite) NSString *offset;
/**
The global link weight, in pixels. If not set, width is calculated per link, depending on the weight value.

**Defaults to** `undefined`.

**Try it**

* [Link weight](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-arcdiagram/link-weight)
*/
@property(nonatomic, readwrite) NSNumber *linkWeight;
/**
A collection of options for the individual nodes. The nodes in an arc diagram are auto-generated instances of `Highcharts.Point`, but options can be applied here and linked by the `id`.
*/
@property(nonatomic, readwrite) NSArray <HINodes *> *nodes;
/**
Whether the series should be placed on the other side of the `plotArea`.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reversed;
/**
Whether nodes with different values should have the same size. If set to true, all nodes are calculated based on the `nodePadding` and current `plotArea`. It is possible to override it using the `marker.radius` option.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *equalNodes;
/**
The option to center links rather than position them one after another

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *centeredLinks;
/**
When using automatic point colors pulled from the global `colors` or series-specific `plotOptions.column.colors` collections, this option determines whether the chart should receive one color per series or one color per point. In styled mode, the `colors` or `series.colors` arrays are not supported, and instead this option gives the points individual color class names on the form `highcharts-color-{n}`.

**Defaults to** `True`.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-false/)
* [True](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
The minimal width for a line of a sankey. By default, 0 values are not shown.

**Defaults to** `0`.

**Try it**

* [Sankey diagram with minimal link height](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-minlinkwidth)
*/
@property(nonatomic, readwrite) NSNumber *minLinkWidth;
/**
The distance between nodes in a sankey diagram in the longitudinal direction. The longitudinal direction means the direction that the chart flows - in a horizontal chart the distance is horizontal, in an inverted chart (vertical), the distance is vertical. If a number is given, it denotes pixels. If a percentage string is given, the distance is a percentage of the rendered node width. A `nodeDistance` of `100%` will render equal widths for the nodes and the gaps between them. This option applies only when the `nodeWidth` option is `auto`, making the node width respond to the number of columns.

**Defaults to** `30`.

**Try it**

* [Sankey with dnode distance of 100% means equal to node width](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-sankey/node-distance)
* [Organization chart with node distance of 50%](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/node-distance)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ nodeDistance;
/**
Set options on specific levels. Takes precedence over series options, but not node and link options.

**Try it**

* [Sunburst chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst)
*/
@property(nonatomic, readwrite) NSArray <HILevels *> *levels;
/**
The width of the border surrounding each column or bar. Defaults to `1` when there is room for a border, but to `0` when the columns are so dense that a border would cover the next column. In styled mode, the stroke width can be set with the `.highcharts-point` rule.

**Try it**

* [2px black border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
The pixel width of each node in a sankey diagram or dependency wheel, or the height in case the chart is inverted. Can be a number or a percentage string. Sankey series also support setting it to `auto`. With this setting, the nodes are sized to fill up the plot area in the longitudinal direction, regardless of the number of levels.

**Defaults to** `20`.

**Try it**

* [Sankey with auto node width combined with node distance](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-sankey/node-distance)
* [Organization chart with node distance of 50%](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/node-distance)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ nodeWidth;
/**
Opacity for the links between nodes in the sankey diagram.

**Defaults to** `0.5`.
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;
/**
Determines color mode for sankey links. Available options: - `from` color of the sankey link will be the same as the 'from node' - `gradient` color of the sankey link will be set to gradient between colors of 'from node' and 'to node' - `to` color of the sankey link will be same as the 'to node'.

**Defaults to** `from`.

**Try it**

* [Vertical sankey diagram with gradients](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/vertical-sankey)
* [Sankey diagram with gradients and explanation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-sankey/link-color-mode)
*/
@property(nonatomic, readwrite) NSString *linkColorMode;
/**
A series specific or series type specific color set to apply instead of the global `colors` when `colorByPoint` is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
The color of the border surrounding each column or bar. In styled mode, the border stroke can be set with the `.highcharts-point` rule.

**Defaults to** `#ffffff`.

**Try it**

* [Dark gray border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-bordercolor/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;

-(NSDictionary *)getParams;

@end
