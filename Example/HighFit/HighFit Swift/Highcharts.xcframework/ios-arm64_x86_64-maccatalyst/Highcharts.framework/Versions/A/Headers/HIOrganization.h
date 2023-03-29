/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HILink.h"
#import "HINodes.h"
#import "HILevels.h"
#import "HIColor.h"


/**
 A `organization` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `organization` series are defined in `plotOptions.organization`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        organization: {
            // shared options for all organization series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'organization'
    }]
 });
 <pre>
 */
@interface HIOrganization: HISeries

/**
Link Styling options
*/
@property(nonatomic, readwrite) HILink *link;
/**
A collection of options for the individual nodes. The nodes in an org chart are auto-generated instances of `Highcharts.Point`, but options can be applied here and linked by the `id`.
*/
@property(nonatomic, readwrite) NSArray <HINodes *> *nodes;
/**
The border color of the node cards.

**Defaults to** `#666666`.

**Try it**

* [Dark gray border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-bordercolor/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
In a horizontal chart, the width of the nodes in pixels. Note that most organization charts are vertical, so the name of this option is counterintuitive.

**Defaults to** `50`.
*/
@property(nonatomic, readwrite) NSNumber *nodeWidth;
/**
The border radius of the node cards.

**Defaults to** `3`.
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
Defines the indentation of a `hanging` layout parent's children. Possible options: - `inherit` (default): Only the first child adds the indentation, children of a child with indentation inherit the indentation. - `cumulative`: All children of a child with indentation add its own indent. The option may cause overlapping of nodes. Then use `shrink` option: - `shrink`: Nodes shrink by the `hangingIndent` value until they reach the `minNodeLength`.

**Defaults to** `inherit`.

**Try it**

* [Every indent increases the indentation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/hanging-cumulative)
* [Every indent decreases the nodes' width](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/hanging-shrink)
*/
@property(nonatomic, readwrite) NSString *hangingIndentTranslation;
/**
In a horizontal chart, the minimum width of the **hanging** nodes only, in pixels. In a vertical chart, the minimum height of the **haning** nodes only, in pixels too. Note: Used only when `hangingIndentTranslation` is set to `shrink`.

**Defaults to** `10`.
*/
@property(nonatomic, readwrite) NSNumber *minNodeLength;
/**
The width of the border surrounding each column or bar. Defaults to `1` when there is room for a border, but to `0` when the columns are so dense that a border would cover the next column. In styled mode, the stroke width can be set with the `.highcharts-point` rule.

**Defaults to** `1`.

**Try it**

* [2px black border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
The indentation in pixels of hanging nodes, nodes which parent has `layout` set to `hanging`.

**Defaults to** `20`.
*/
@property(nonatomic, readwrite) NSNumber *hangingIndent;
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
The padding between nodes in a sankey diagram or dependency wheel, in pixels. If the number of nodes is so great that it is possible to lay them out within the plot area with the given `nodePadding`, they will be rendered with a smaller padding as a strategy to avoid overflow.

**Defaults to** `10`.
*/
@property(nonatomic, readwrite) NSNumber *nodePadding;
/**
Set options on specific levels. Takes precedence over series options, but not node and link options.

**Try it**

* [Sunburst chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst)
*/
@property(nonatomic, readwrite) NSArray <HILevels *> *levels;
/**
Opacity for the links between nodes in the sankey diagram.

**Defaults to** `0.5`.
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;
/**
A series specific or series type specific color set to apply instead of the global `colors` when `colorByPoint` is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
When `true`, the columns will center in the category, ignoring null or missing points. When `false`, space will be reserved for null or missing points.

**Try it**

* [Center in category](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-column/centerincategory/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *centerInCategory;

-(NSDictionary *)getParams;

@end
