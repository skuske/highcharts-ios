/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIButtonOptions.h"
#import "HIBreadcrumbs.h"
#import "HIBindings.h"
#import "HIEvents.h"
#import "HIPopup.h"
#import "HIAnnotationsOptions.h"
#import "HIAnimationOptionsObject.h"
#import "HICSSObject.h"
#import "HIColor.h"


/**
A collection of options for buttons and menus appearing in the exporting module or in Stock Tools.
*/
@interface HINavigation: HIChartsJSONSerializable

/**
CSS styles for the popup menu appearing by default when the export icon is clicked. This menu is rendered in HTML.

**Defaults to** `{"background": "#ffffff", "borderRadius": "3px", "padding": "0.5em"}`.

**Try it**

* [Light gray menu background](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menustyle/)
*/
@property(nonatomic, readwrite) HICSSObject *menuStyle;
/**
A collection of options for buttons appearing in the exporting module. In styled mode, the buttons are styled with the `.highcharts-contextbutton` and `.highcharts-button-symbol` classes.
*/
@property(nonatomic, readwrite) HIButtonOptions *buttonOptions;
/**
Additional options to be merged into all annotations.

**Try it**

* [Set red color of all line annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/stock/stocktools/navigation-annotation-options)
*/
@property(nonatomic, readwrite) HIAnnotationsOptions *annotationsOptions;
/**
A CSS class name where all bindings will be attached to. Multiple charts on the same page should have separate class names to prevent duplicating events. Default value of versions < 7.0.4 `highcharts-bindings-wrapper`

**Defaults to** `highcharts-bindings-container`.
*/
@property(nonatomic, readwrite) NSString *bindingsClassName;
/**
Options for breadcrumbs. Breadcrumbs general options are defined in `navigation.breadcrumbs`. Specific options for drilldown are set in `drilldown.breadcrumbs` and for tree-like series traversing, in `plotOptions[series].breadcrumbs`.
*/
@property(nonatomic, readwrite) HIBreadcrumbs *breadcrumbs;
/**
CSS styles for the hover state of the individual items within the popup menu appearing by default when the export icon is clicked. The menu items are rendered in HTML.

**Defaults to** `{"background": "#f2f2f2" }`.

**Try it**

* [Bold text on hover](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menuitemhoverstyle/)
*/
@property(nonatomic, readwrite) HICSSObject *menuItemHoverStyle;
/**
CSS styles for the individual items within the popup menu appearing by default when the export icon is clicked. The menu items are rendered in HTML. Font size defaults to `11px` on desktop and `14px` on touch devices.

**Defaults to** `{"padding": "0.5em", "color": "#333333", "background": "none", "borderRadius": "3px", "fontSize": "0.8em", "transition": "background 250ms, color 250ms"}`.

**Try it**

* [Add a grey stripe to the left](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menuitemstyle/)
*/
@property(nonatomic, readwrite) HICSSObject *menuItemStyle;
/**
Bindings definitions for custom HTML buttons. Each binding implements simple event-driven interface: - `className`: classname used to bind event to - `init`: initial event, fired on button click - `start`: fired on first click on a chart - `steps`: array of sequential events fired one after another on each  of users clicks - `end`: last event to be called after last step event
*/
@property(nonatomic, readwrite) HIBindings *bindings;
/**
Events to communicate between Stock Tools and custom GUI.
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
Path where Highcharts will look for icons. Change this to use icons from a different server.
*/
@property(nonatomic, readwrite) NSString *iconsURL;
/**
Text styles for the legend page navigation.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
The color of the inactive up or down arrow in the legend page navigation. .

**Defaults to** `#cccccc`.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) HIColor *inactiveColor;
/**
Whether to enable the legend navigation. In most cases, disabling the navigation results in an unwanted overflow. See also the [adapt chart to legend](https://github.com/highcharts/adapt-chart-to-legend) plugin for a solution to extend the chart height to make room for the legend, optionally in exported charts only.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The pixel size of the up and down arrows in the legend paging navigation.

**Defaults to** `12`.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) NSNumber *arrowSize;
/**
How to animate the pages when navigating up or down. A value of `true` applies the default navigation given in the `chart.animation` option. Additional options can be given as an object containing values for easing and duration.

**Defaults to** `true`.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
The color for the active up or down arrow in the legend page navigation.

**Defaults to** `#0022ff`.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) HIColor *activeColor;
/**
Translations for all field names used in popup.
*/
@property(nonatomic, readwrite) HIPopup *popup;

-(NSDictionary *)getParams;

@end
