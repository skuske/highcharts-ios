!/**
 * Highcharts JS v11.4.3 (2024-05-22)
 *
 * Arc diagram module
 *
 * (c) 2021 Piotr Madej
 *
 * License: www.highcharts.com/license
 */function(e){"object"==typeof module&&module.exports?(e.default=e,module.exports=e):"function"==typeof define&&define.amd?define("highcharts/modules/arc-diagram",["highcharts","highcharts/modules/sankey"],function(t){return e(t),e.Highcharts=t,e}):e("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(e){"use strict";var t=e?e._modules:{};function i(e,t,i,s){e.hasOwnProperty(t)||(e[t]=s.apply(null,i),"function"==typeof CustomEvent&&window.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:t,module:e[t]}})))}i(t,"Series/ArcDiagram/ArcDiagramPoint.js",[t["Series/NodesComposition.js"],t["Core/Series/SeriesRegistry.js"],t["Core/Utilities.js"]],function(e,t,i){let{seriesTypes:{sankey:{prototype:{pointClass:s}}}}=t,{extend:o}=i;class a extends s{isValid(){return!0}}return o(a.prototype,{setState:e.setNodeState}),a}),i(t,"Series/ArcDiagram/ArcDiagramSeriesDefaults.js",[],function(){return{centeredLinks:!1,equalNodes:!1,dataLabels:{linkTextPath:{attributes:{startOffset:"25%"}}},marker:{fillOpacity:1,lineWidth:0,states:{},symbol:"circle"},offset:"100%",reversed:!1}}),i(t,"Series/ArcDiagram/ArcDiagramSeries.js",[t["Series/ArcDiagram/ArcDiagramPoint.js"],t["Series/ArcDiagram/ArcDiagramSeriesDefaults.js"],t["Series/Sankey/SankeyColumnComposition.js"],t["Core/Series/Series.js"],t["Core/Series/SeriesRegistry.js"],t["Core/Renderer/SVG/SVGRenderer.js"],t["Core/Utilities.js"]],function(e,t,i,s,o,a,n){let{prototype:{symbols:r}}=a,{seriesTypes:{column:l,sankey:h}}=o,{crisp:d,extend:p,merge:m,pick:u,relativeLength:c}=n;class g extends h{createNodeColumns(){let e=this,t=e.chart,s=i.compose([],e);return s.sankeyColumn.maxLength=t.inverted?t.plotHeight:t.plotWidth,s.sankeyColumn.getTranslationFactor=e=>{let i=s.slice(),o=this.options.minLinkWidth||0,a,n=0,r,l,h=0,d=1,p=0,m=(t.plotSizeX||0)-(e.options.marker&&e.options.marker.lineWidth||0)-(s.length-1)*e.nodePadding;for(;s.length;){for(n=m/s.sankeyColumn.sum(),a=!1,r=s.length;r--;){l=s[r].getSum()*n*d;let e=Math.min(t.plotHeight,t.plotWidth);l>e?d=Math.min(e/l,d):l<o&&(s.splice(r,1),m-=o,l=o,a=!0),p+=l*(1-d)/2,h=Math.max(h,l)}if(!a)break}return s.length=0,i.forEach(e=>{e.scale=d,s.push(e)}),s.sankeyColumn.maxRadius=h,s.sankeyColumn.scale=d,s.sankeyColumn.additionalSpace=p,n},s.sankeyColumn.offset=function(i,o){let a=i.series.options.equalNodes,n=e.nodePadding,r=Math.min(t.plotWidth,t.plotHeight,(s.sankeyColumn.maxLength||0)/e.nodes.length-n),l=s.sankeyColumn.additionalSpace||0,h;for(let t=0;t<s.length;t++){let d=s[t].getSum()*(s.sankeyColumn.scale||0),p=a?r:Math.max(d*o,e.options.minLinkWidth||0);if(h=d?p+n:0,s[t]===i)return{relativeLeft:l+c(i.options.offset||0,h)};l+=h}},e.nodes.forEach(function(e){e.column=0,s.push(e)}),[s]}translateLink(e){let t=e.fromNode,i=e.toNode,s=this.chart,o=this.translationFactor,a=e.options,n=this.options,r=u(a.linkWeight,n.linkWeight,Math.max((e.weight||0)*o*t.scale,this.options.minLinkWidth||0)),l=e.series.options.centeredLinks,h=t.nodeY,d=(t,i)=>{let s=(t.offset(e,i)||0)*o;return Math.min(t.nodeX+s,t.nodeX+(t.shapeArgs&&t.shapeArgs.height||0)-r)},p=l?t.nodeX+((t.shapeArgs.height||0)-r)/2:d(t,"linksFrom"),m=l?i.nodeX+((i.shapeArgs.height||0)-r)/2:d(i,"linksTo"),c=h;p>m&&([p,m]=[m,p]),n.reversed&&([p,m]=[m,p],c=(s.plotSizeY||0)-c),e.shapeType="path",e.linkBase=[p,p+r,m,m+r];let g=(m+r-p)/Math.abs(m+r-p)*u(n.linkRadius,Math.min(Math.abs(m+r-p)/2,t.nodeY-Math.abs(r)));e.shapeArgs={d:[["M",p,c],["A",(m+r-p)/2,g,0,0,1,m+r,c],["L",m,c],["A",(m-p-r)/2,g-r,0,0,0,p+r,c],["Z"]]},e.dlBox={x:p+(m-p)/2,y:c-g,height:r,width:0},e.tooltipPos=s.inverted?[(s.plotSizeY||0)-e.dlBox.y-r/2,(s.plotSizeX||0)-e.dlBox.x]:[e.dlBox.x,e.dlBox.y+r/2],e.y=e.plotY=1,e.x=e.plotX=1,e.color||(e.color=t.color)}translateNode(e,t){let i=this.translationFactor,s=this.chart,o=s.inverted?s.plotWidth:s.plotHeight,a=this.options,n=Math.min(s.plotWidth,s.plotHeight,o/e.series.nodes.length-this.nodePadding),l=e.getSum()*(t.sankeyColumn.scale||0),p=a.equalNodes?n:Math.max(l*i,this.options.minLinkWidth||0),c=a.marker?.lineWidth||0,g=t.sankeyColumn.offset(e,i),f=d(u(g&&g.absoluteLeft,(t.sankeyColumn.left(i)||0)+(g&&g.relativeLeft||0)),c),y=m(a.marker,e.options.marker),k=y.symbol,S=y.radius,C=parseInt(a.offset,10)*((s.inverted?s.plotWidth:s.plotHeight)-(d(this.colDistance*(e.column||0)+(y.lineWidth||0)/2,c)+(t.sankeyColumn.scale||0)*(t.sankeyColumn.maxRadius||0)/2))/100;if(e.sum=l,l){e.nodeX=f,e.nodeY=C;let t=e.options.width||a.width||p,i=e.options.height||a.height||p,o=C;a.reversed&&(o=(s.plotSizeY||0)-C,s.inverted&&(o=(s.plotSizeY||0)-C)),this.mapOptionsToLevel&&(e.dlOptions=h.getDLOptions({level:this.mapOptionsToLevel[e.level],optionsPoint:e.options})),e.plotX=1,e.plotY=1,e.tooltipPos=s.inverted?[(s.plotSizeY||0)-o-i/2,(s.plotSizeX||0)-f-t/2]:[f+t/2,o+i/2],e.shapeType="path",e.shapeArgs={d:r[k||"circle"](f,o-(S||i)/2,S||t,S||i),width:S||t,height:S||i},e.dlBox={x:f+t/2,y:o,height:0,width:0}}else e.dlOptions={enabled:!1}}drawDataLabels(){if(this.options.dataLabels){let e=this.options.dataLabels.textPath;l.prototype.drawDataLabels.call(this,this.nodes),this.options.dataLabels.textPath=this.options.dataLabels.linkTextPath,l.prototype.drawDataLabels.call(this,this.data),this.options.dataLabels.textPath=e}}pointAttribs(e,t){if(e&&e.isNode){let{...e}=s.prototype.pointAttribs.apply(this,arguments);return e}return super.pointAttribs.apply(this,arguments)}markerAttribs(e){return e.isNode?super.markerAttribs.apply(this,arguments):{}}}return g.defaultOptions=m(h.defaultOptions,t),p(g.prototype,{orderNodes:!1}),g.prototype.pointClass=e,o.registerSeriesType("arcdiagram",g),g}),i(t,"masters/modules/arc-diagram.src.js",[t["Core/Globals.js"]],function(e){return e})});