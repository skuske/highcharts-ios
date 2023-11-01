/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIDataLabels.h"
#import "HIMarker.h"
#import "HIColor.h"


/**
A collection of options for the individual nodes. The nodes in a networkgraph diagram are auto-generated instances of `Highcharts.Point`, but options can be applied here and linked by the `id`.

**Try it**

* [Networkgraph diagram with node options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/data-options/)
*/
@interface HINodes: HIChartsJSONSerializable

/**
The color index of the auto generated node, especially for use in styled mode.
*/
@property(nonatomic, readwrite) NSNumber *colorIndex;
/**
The color of the auto generated node.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Individual data label for each node. The options are the same as the ones for `series.networkgraph.dataLabels`.
*/
@property(nonatomic, readwrite) NSArray <HIDataLabels *> *dataLabels;
/**
Mass of the node. By default, each node has mass equal to it's marker radius . Mass is used to determine how two connected nodes should affect each other: Attractive force is multiplied by the ratio of two connected nodes; if a big node has weights twice as the small one, then the small one will move towards the big one twice faster than the big one to the small one .

**Try it**

* [Mass determined by marker.radius](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/ragdoll/)
*/
@property(nonatomic, readwrite) NSNumber *mass;
/**
Options for the node markers.
*/
@property(nonatomic, readwrite) HIMarker *marker;
/**
The id of the auto-generated node, refering to the `from` or `to` setting of the link.
*/
@property(nonatomic, readwrite) NSString *id;
/**
The name to display for the node in data labels and tooltips. Use this when the name is different from the `id`. Where the id must be unique for each node, this is not necessary for the name.

**Try it**

* [Networkgraph diagram with node options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/data-options/)
*/
@property(nonatomic, readwrite) NSString *name;
/**
The vertical offset of a node. Positive values shift the node down, negative shift it up. If a percantage string is given, the node is offset by the percentage of the node size.

**Try it**

* [Specified node offset](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-node-column/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ offsetVertical;
/**
An optional level index of where to place the node. The default behaviour is to place it next to the preceding node. Alias of `nodes.column`, but in inverted sankeys and org charts, the levels are laid out as rows.
*/
@property(nonatomic, readwrite) NSNumber *level;
/**
The horizontal offset of a node. Positive values shift the node right, negative shift it left. If a percantage string is given, the node is offset by the percentage of the node size.

**Try it**

* [Specified node offset](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-node-column/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ offsetHorizontal;
/**
An optional column index of where to place the node. The default behaviour is to place it next to the preceding node. Note that this option name is counter intuitive in inverted charts, like for example an organization chart rendered top down. In this case the "columns" are horizontal.

**Try it**

* [Specified node column](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-node-column/)
*/
@property(nonatomic, readwrite) NSNumber *column;
/**
An image for the node card, will be inserted by the default `dataLabel.nodeFormatter`.

**Try it**

* [Org chart with images](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/organization-chart)
*/
@property(nonatomic, readwrite) NSString *image;
/**
The job title for the node card, will be inserted by the default `dataLabel.nodeFormatter`.

**Try it**

* [Org chart with job titles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/organization-chart)
*/
@property(nonatomic, readwrite) NSString *title;
/**
Layout for the node's children. If `hanging`, this node's children will hang below their parent, allowing a tighter packing of nodes in the diagram. Note: Since @next version, the `hanging` layout is set by default for children of a parent using `hanging` layout.

**Defaults to** `normal`.

**Try it**

* [Hanging layout](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/organization-chart)
*/
@property(nonatomic, readwrite) NSString *layout;
/**
The job description for the node card, will be inserted by the default `dataLabel.nodeFormatter`.

**Try it**

* [Org chart with job descriptions](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/organization-chart)
*/
@property(nonatomic, readwrite) NSString *definition;

-(NSDictionary *)getParams;

@end
