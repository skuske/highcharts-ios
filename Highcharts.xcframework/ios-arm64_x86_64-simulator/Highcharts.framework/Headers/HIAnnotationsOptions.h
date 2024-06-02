/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HILabels.h"
#import "HIControlPointOptions.h"
#import "HIEvents.h"
#import "HILabelOptions.h"
#import "HIShapes.h"
#import "HIShapeOptions.h"
#import "HIAnimationOptionsObject.h"


/**
Additional options to be merged into all annotations.

**Try it**

* [Set red color of all line annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/stock/stocktools/navigation-annotation-options)
*/
@interface HIAnnotationsOptions: HIChartsJSONSerializable

/**
An array of labels for the annotation. For options that apply to multiple labels, they can be added to the `labelOptions`.
*/
@property(nonatomic, readwrite) NSArray <HILabels *> *labels;
/**
Whether to hide the part of the annotation that is outside the plot area.

**Defaults to** `True`.

**Try it**

* [Crop line annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-crop-overflow/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *crop;
/**
Whether the annotation is visible.

**Defaults to** `True`.

**Try it**

* [Set annotation visibility](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/visible/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *visible;
/**
Sets an ID for an annotation. Can be user later when removing an annotation in `Chart#removeAnnotation(id)` method.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ id;
/**
Options for annotation's control points. Each control point inherits options from controlPointOptions object. Options from the controlPointOptions can be overwritten by options in a specific control point.
*/
@property(nonatomic, readwrite) HIControlPointOptions *controlPointOptions;
/**
Allow an annotation to be draggable by a user. Possible values are `'x'`, `'xy'`, `'y'` and `''` (disabled).

**Defaults to** `xy`.

**Try it**

* [Annotations draggable: 'xy'](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/draggable/)
*/
@property(nonatomic, readwrite) NSString *draggable;
/**
Enable or disable the initial animation when a series is displayed for the `annotation`. The animation can also be set as a configuration object. Please note that this option only applies to the initial animation. For other animations, see `chart.animation` and the animation parameter under the API methods. The following properties are supported: - `defer`: The animation delay time in milliseconds.

**Try it**

* [Animation defer settings](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/defer/)
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
Events available in annotations.
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
Options for annotation's labels. Each label inherits options from the labelOptions object. An option from the labelOptions can be overwritten by config for a specific label.
*/
@property(nonatomic, readwrite) HILabelOptions *labelOptions;
/**
The Z index of the annotation.

**Defaults to** `6`.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
An array of shapes for the annotation. For options that apply to multiple shapes, then can be added to the `shapeOptions`.
*/
@property(nonatomic, readwrite) NSArray <HIShapes *> *shapes;
/**
Options for annotation's shapes. Each shape inherits options from the shapeOptions object. An option from the shapeOptions can be overwritten by config for a specific shape.
*/
@property(nonatomic, readwrite) HIShapeOptions *shapeOptions;

-(NSDictionary *)getParams;

@end
