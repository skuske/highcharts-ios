!/**
 * Highstock JS v11.4.3 (2024-05-22)
 *
 * Advanced Highcharts Stock tools
 *
 * (c) 2010-2024 Highsoft AS
 * Author: Torstein Honsi
 *
 * License: www.highcharts.com/license
 */function(e){"object"==typeof module&&module.exports?(e.default=e,module.exports=e):"function"==typeof define&&define.amd?define("highcharts/modules/full-screen",["highcharts"],function(t){return e(t),e.Highcharts=t,e}):e("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(e){"use strict";var t=e?e._modules:{};function n(e,t,n,s){e.hasOwnProperty(t)||(e[t]=s.apply(null,n),"function"==typeof CustomEvent&&window.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:t,module:e[t]}})))}n(t,"Extensions/Exporting/Fullscreen.js",[t["Core/Renderer/HTML/AST.js"],t["Core/Globals.js"],t["Core/Utilities.js"]],function(e,t,n){let{composed:s}=t,{addEvent:r,fireEvent:l,pushUnique:i}=n;function o(){this.fullscreen=new u(this)}class u{static compose(e){i(s,"Fullscreen")&&r(e,"beforeRender",o)}constructor(e){this.chart=e,this.isOpen=!1;let t=e.renderTo;!this.browserProps&&("function"==typeof t.requestFullscreen?this.browserProps={fullscreenChange:"fullscreenchange",requestFullscreen:"requestFullscreen",exitFullscreen:"exitFullscreen"}:t.mozRequestFullScreen?this.browserProps={fullscreenChange:"mozfullscreenchange",requestFullscreen:"mozRequestFullScreen",exitFullscreen:"mozCancelFullScreen"}:t.webkitRequestFullScreen?this.browserProps={fullscreenChange:"webkitfullscreenchange",requestFullscreen:"webkitRequestFullScreen",exitFullscreen:"webkitExitFullscreen"}:t.msRequestFullscreen&&(this.browserProps={fullscreenChange:"MSFullscreenChange",requestFullscreen:"msRequestFullscreen",exitFullscreen:"msExitFullscreen"}))}close(){let e=this,t=e.chart,n=t.options.chart;l(t,"fullscreenClose",null,function(){e.isOpen&&e.browserProps&&t.container.ownerDocument instanceof Document&&t.container.ownerDocument[e.browserProps.exitFullscreen](),e.unbindFullscreenEvent&&(e.unbindFullscreenEvent=e.unbindFullscreenEvent()),t.setSize(e.origWidth,e.origHeight,!1),e.origWidth=void 0,e.origHeight=void 0,n.width=e.origWidthOption,n.height=e.origHeightOption,e.origWidthOption=void 0,e.origHeightOption=void 0,e.isOpen=!1,e.setButtonText()})}open(){let e=this,t=e.chart,n=t.options.chart;l(t,"fullscreenOpen",null,function(){if(n&&(e.origWidthOption=n.width,e.origHeightOption=n.height),e.origWidth=t.chartWidth,e.origHeight=t.chartHeight,e.browserProps){let n=r(t.container.ownerDocument,e.browserProps.fullscreenChange,function(){e.isOpen?(e.isOpen=!1,e.close()):(t.setSize(null,null,!1),e.isOpen=!0,e.setButtonText())}),s=r(t,"destroy",n);e.unbindFullscreenEvent=()=>{n(),s()};let l=t.renderTo[e.browserProps.requestFullscreen]();l&&l.catch(function(){alert("Full screen is not supported inside a frame.")})}})}setButtonText(){let t=this.chart,n=t.exportDivElements,s=t.options.exporting,r=s&&s.buttons&&s.buttons.contextButton.menuItems,l=t.options.lang;if(s&&s.menuItemDefinitions&&l&&l.exitFullscreen&&l.viewFullscreen&&r&&n){let t=n[r.indexOf("viewFullscreen")];t&&e.setElementHTML(t,this.isOpen?l.exitFullscreen:s.menuItemDefinitions.viewFullscreen.text||l.viewFullscreen)}}toggle(){this.isOpen?this.close():this.open()}}return u}),n(t,"masters/modules/full-screen.src.js",[t["Core/Globals.js"],t["Extensions/Exporting/Fullscreen.js"]],function(e,t){return e.Fullscreen=e.Fullscreen||t,e.Fullscreen.compose(e.Chart),e})});