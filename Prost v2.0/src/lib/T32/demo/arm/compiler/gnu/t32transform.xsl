<?xml version="1.0" encoding="ISO-8859-1"?>

<!--
__________________________________________________________________________________
@Title: TRACE32 XML to HTML converter
@Description:
 XSLT stylesheet to convert the XML output generated with the following TRACE32
 commands to a HTML page:
   List.EXPORT                [<addr.range>],<file> [/Append] [/COVerage] [/ISTAT]
   BookMark.EXPORT            [<addr.range>],<file> [/Append]
   COVerage.EXPORT.ListModule [<addr.range>],<file> [/Append]
   COVerage.EXPORT.ListFunc   [<addr.range>],<file> [/Append]
   COVerage.EXPORT.ListLine   [<addr.range>],<file> [/Append]
   COVerage.EXPORT.ListVar    [<addr.range>],<file> [/Append]
   COVerage.EXPORT.Group                     <file> [/Append]

 An XML file can be opened directly inside a web browser if t32transform.xsl
 is located in the same folder.

 If you're using Google Chrome please start it with the
 option -allow-file-access-from-files

 The generated HTML accepts currently the following GET parameters:
   mode=mix/hll/asm            : Display list immediately in MIX, HLL or ASM view
   color=normal/gray/truewhite : Use colors (normal) or paint in grayscale (gray)
 E.g. file:///C:/T32/demo/coverage/example.xml?mode=hll&color=gray
@Author: HLG
@Keywords: coverage, XML, XSLT
@Copyright: (C) 1989-2015 Lauterbach GmbH, licensed for use with TRACE32(R) only
__________________________________________________________________________________
$Id: t32transform.xsl 14648 2019-07-15 07:16:21Z dorthofer $
-->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:exslt="http://exslt.org/common"
                xmlns:msxsl="urn:schemas-microsoft-com:xslt"
                extension-element-prefixes="exslt msxsl"
>
<xsl:output method="html" media-type="text/html" indent="no" encoding="ISO-8859-1" omit-xml-declaration="yes"
            doctype-public="-//W3C//DTD HTML 4.01 Transitional//EN" doctype-system="http://www.w3.org/TR/html4/loose.dtd" />

<xsl:variable name="style">
html, body {
	height:100%;
}
body {
	font-family:Arial, Helvetica, sans-serif;
	font-size:14px;
	padding: 0 0 5px 5px;
}
h1 {
	font-size:28px;
	counter-reset:h2;
}
h2 {
	font-size:24px;
}
h2:before {
	content:counter(h2) ". ";
	counter-increment:h2;
}
a,
a:link,
a:visited,
a:hover,
a:active {
	color:black;
	text-decoration:none;
}
a:hover {
	text-decoration:underline;
}


<!-- /*** General table style ***/ -->
table {
	margin:0;
	border-spacing:0;
	border-collapse:separate;
	empty-cells: show;
}
td, th {
	padding:1px 4px 1px 8px;
	border:none 0 transparent;
	border-top-width: 1px;
	vertical-align:top;
	text-align:left;
}
th {
	padding-top:2px;
	padding-bottom:2px;
	border-top: solid 1px black !important;
	font-weight:bold;
}
td.first-child, th.first-child, /* IE 7 */
td:first-child, th:first-child {
	border-left:   solid 1px black !important;
}
td:last-child, th:last-child {
	border-right:  solid 1px black;
}
td.last-child, th.last-child { /* IE 8 */
	border-right:  solid 1px black;
}
tr.first-child td, /* IE 7 */
tr:first-child td {
	border-top: solid 1px black;
}
tr:last-child td {
	border-bottom: solid 1px black !important;
}
tr.last-child td { /* IE 8 */
	border-bottom: solid 1px black !important;
}
tbody tr:hover {
	background-color:#FFFFE0; <!-- /* LightYellow */ -->
}


<!-- /*** Style for ADDR class ***/ -->
.addr {
	border-right: solid 1px black;
}
td.addr, a.addr{
	font-family:"Courier New", Courier, monospace;
	font-weight:bold;
}
td.addr {
	text-align:right;
	white-space:nowrap; <!-- /* collapse white-space, never wrap lines */ -->
}


<!-- /*** Style for COV class ***/ -->
tr td.cov, tr th.cov {
	padding-left:6px;
	border:solid 1px black;
	border-color: black;
	border-bottom-width: 0;
}
tr td.cov {
	padding-top:4px;
	font-size:11px;
	font-family:Arial, Helvetica, sans-serif;
	font-weight:bold;
	color:black;
}
tr.cov_never td.cov {
	background-color:#FF0000;  <!-- /* red */ -->
}
tr.cov_partial td.cov {
	background-color:#FFA500;  <!-- /* orange */ -->
}
tr.cov_ok td.cov {
	color:#DCDCDC;
	background-color:#008000;  <!-- /* green */ -->
	font-weight:normal;
}
tr.nocov_never td.cov {
	background-color:#ff9191;  <!-- /* very light red */ -->
}
tr.nocov_partial td.cov {
	background-color:#ffd691;  <!-- /* very light orange */ -->
}
tr.nocov_ok td.cov {
	background-color:#a0dba0;  <!-- /* very light green */ -->
}

body.truewhite tr.cov_ok td.cov {
	color:white;
}
body.gray tr.cov_never td.cov {
	background-color:#909090
}
body.gray tr.cov_partial td.cov {
	background-color:#DCDCDC;
}
body.gray tr.cov_ok td.cov {
	color:black;
	background-color:white;
}
body.gray tr.nocov_never   td.cov,
body.gray tr.nocov_partial td.cov,
body.gray tr.nocov_ok      td.cov {
	background-color:white;
}


<!-- /*** Style for ISTAT class ***/ -->
.icnt,
.iclk {
	text-align:right;
}
td.iclk,
td.icpi2{
	font-size: 12px;
	padding-top:4px;
}
th.icpi {
	text-align:center;
}
td.icpi {
	text-align:right;
	padding-right:0;
}
td.icpi2 {
	text-align:left;
	padding-left:0;
}


<!-- /*** Style for GRAPH class ***/ -->
td.graph, th.graph {
	border-left: solid 1px black;
	border-right:solid 1px black;
}
td.graph {
	padding: 6px 6px 0 0;
}
th.graph {
	padding-left:1px;
	padding-right:1px;
}
.graph table {
	width:100%;
	min-width:9em;
}
#t32-ListVar .graph table {
	min-width:4em;
}
#t32-ListLine .graph table {
	min-width:7em;
}
td.graph table td {
	font-size:0;
	line-height:0;
	height:0;
	padding:0;
	border: 0 none black;
	border-left-style:   none !important;
	border-bottom-style: none !important;
	background-color:transparent;
	width:100%;
}
td.graph table td.first-child, /* IE 7 */
td.graph table td:first-child {
	border-top:   8px solid gray;
	border-right: 2px solid gray;
	width:0;
}
th.graph table td { <!-- /* Caption: "0% - 50% - 100%" */ -->
	padding:0;
	border-style: none !important;
	text-align:center;
	width:33.3%;
	font-size:12px;
	font-weight:normal;
	height:20px;
	vertical-align:middle;
}
th.graph table td.first-child, /* IE 7 */
th.graph table td:first-child { <!-- /* Caption: "0%" */ -->
	text-align:left;
}
th.graph table td:last-child { <!-- /* Caption: "100%" */ -->
	text-align:right;
}
th.graph table td.last-child { /* IE 8 */
	text-align:right;
}


<!-- /*** BookMarks ***/ -->
#t32-bookmarks td {
	border-top: solid 1px #D3D3D3;
}
#t32-bookmarks td.bmname,
#t32-bookmarks th.bmname {
	border-right: solid 1px black;
}
#t32-bookmarks td.src {
	max-width:15em;
	word-break:break-all;
}
#t32-bookmarks td.remark {
	min-width:20em;
}


<!-- /*** Data.List ***/ -->
tr.hll {
	background-color:#F3F6F8;
}
body.gray tr.hll.nocov_never   td.cov,
body.gray tr.hll.nocov_partial td.cov,
body.gray tr.hll.nocov_ok      td.cov,
body.gray tr.hll {
	background-color:#F9F9F9;
}
tbody tr.hll:hover  {
	background-color:#FFFFE0; <!-- /* LightYellow */ -->
}

#t32-list tr td {
	border-top: solid 1px #D3D3D3;
}
#t32-list tr.hll + tr.hll td {
	border-top-style: none;
}
#t32-list tr.srcfile + tr td,
#t32-list tr.srcfile td {
	border-top-color: black;
}
#t32-list tr td.cov {
	border-top-color: black;
}
#t32-list tr + tr.cov_ok      td.cov,
#t32-list tr + tr.cov_partial td.cov,
#t32-list tr + tr.cov_never   td.cov {
	border-top-style: solid;
}

#t32-list tr.hll {
	color:#0000CD;
}
.gray #t32-list tr.hll {
	color:#303030;
}
#t32-list tr.hll td.code {
	font-style:italic;
	white-space:pre-wrap; <!-- /* preserve white-space, wrap lines when required */ -->
}
#t32-list tr.asm td.code {
	word-spacing:-2px;
<!-- /*
	letter-spacing: -1px;  /* wkhtmltopdf seems to get mad with letter-spacing */
*/ -->
	white-space:pre;
}
#t32-list td.code,
#t32-list td.mnemo,
#t32-list td.label {
	font-family:"Courier New", Courier, monospace;
	font-weight:bold;
}
#t32-list td.code{
	font-weight:normal;
}
#t32-list td.mnemo {
	white-space:pre-wrap; <!-- /* preserve white-space, wrap lines when required */ -->
}
table#t32-list .cov {
	border-right-style: none;
}
table#t32-list .addr,
table#t32-list .icnt {
	border-left: solid 1px black;
}
#t32-list.noHLL tr.hll,
#t32-list.noASM tr.asm {
	display:none;
}
#t32-list.noASM tr.last_hll td {
	border-bottom: solid 1px black;
}
#t32-list td.remark {
	font-size:95%;
	font-family:Arial, Helvetica, sans-serif;
	background-color:yellow;
	color:black;
}
.gray #t32-list td.remark {
	background-color:#DCDCDC;
}
#t32-list td.remark.hllonly {
	background-color:transparent;
}
#t32-list td.remark.hllonly * {
	display:none;
}
#t32-list.noASM td.remark.hllonly {
	background-color:yellow;
}
#t32-list.noASM td.remark.hllonly * {
	display:inline;
}
#t32-list td.remark .addr {
	border-style:none;
	padding: 0 5px 0 0;
	font-family:"Courier New", Courier, monospace;
	font-weight:normal;
}
.gray #t32-list.noASM td.remark.hllonly {
	background-color:#DCDCDC;
}


<!-- /*** COVerage.List... ***/ -->
table.t32-coverage td.tree{
	min-width:120px;
	padding-left:4px;
	padding-right:4px;
}
table.t32-coverage tr.var      td.tree,
table.t32-coverage tr.item     td.tree,
table.t32-coverage tr.function td.tree {
	min-width:104px;
	padding-left:20px;
}
table.t32-coverage tr.line td.tree {
	min-width:84px;
	padding-left:36px;
	padding-right:8px;
	color:#0000CD;
}
table.t32-coverage tr.total td.tree,
table.t32-coverage tr.group td.tree {
	font-weight: bold;
}
table.t32-coverage tr.line td.tree a {
	color:#0000CD;
}
.gray table.t32-coverage tr.line td.tree,
.gray table.t32-coverage tr.line td.tree a {
	color:#303030;
}
table#t32-ListModule.t32-coverage td.tree{
	min-width:116px;
	padding-left:8px;
}
table.t32-coverage td.ratio {
	text-align:right;
}
table.t32-coverage .cnt {
	text-align:right;
	min-width:2.5em;
	padding-right:3px;
	padding-left:5px;
}
table.t32-coverage th {
	vertical-align:middle;
}
table.t32-coverage th.cnt {
	width:2.5em;
	text-align:center;
	padding:0;
	font-size:12px;
	line-height:12px;
}
table.t32-coverage tr :nth-child(7),
table.t32-coverage tr :nth-child(11) {
	border-left: 1px solid black;
}

table.t32-coverage tr .cnt:nth-child(7) {
	background-color:#c8f8c8;  <!-- /* very light green */ -->
}
table.t32-coverage tr .cnt:nth-child(8),
table.t32-coverage tr .cnt:nth-child(9) {
	background-color:#fff6ac;  <!-- /* very light orange */ -->
}
table.t32-coverage tr .cnt:nth-child(10) {
	background-color:#ffd8d8;  <!-- /* very light red */ -->
}
table#t32-ListVar tr .cnt,
.gray table.t32-coverage tr .cnt {
	background-color:transparent;
}

table.t32-coverage tr:hover td.cnt:nth-child(7) {
	background-color:#b8f8b8;
}
table.t32-coverage tr:hover td.cnt:nth-child(8),
table.t32-coverage tr:hover td.cnt:nth-child(9) {
	background-color:#fff0a4;
}
table.t32-coverage tr:hover td.cnt:nth-child(10) {
	background-color:#ffc8c8;
}
table#t32-ListVar tr:hover td.cnt,
.gray table.t32-coverage tr:hover td.cnt {
	background-color:#FFFFE0; <!-- /* LightYellow  */ -->
}

table#t32-ListVar   tr + tr.module   > td,
table#t32-ListFunc  tr + tr.module   > td,
table#t32-ListGroup tr + tr.group    > td,
table#t32-ListLine  tr + tr.function > td {
	border-top: solid 1px #D3D3D3;
}
table#t32-ListLine  tr.module > td {
	border-top: solid 1px black;
}
table.t32-coverage tr + tr > td.cov {
	border-top: solid 1px black !important;
}
table.t32-coverage tr.total > td {
	border-top: solid 1px black;
}


<!-- /*** Control-bar on the bottom of the window ***/ -->
#ctrl {
	border-top:solid 1px black;
	position:fixed;
	bottom:0px;
	left:0;
	margin:0;
	width:100%;
	height:25px;
	line-height:25px;
	background-color:#D3D3D3;
}
#ctrl form  {
	display:inline-block;
	padding:0 2px;
	vertical-align:middle;
}
#ctrl p  {
	padding:0;
	margin:0 0 0 40px;
	display:inline-block;
	font-size:11px;
	vertical-align:bottom;
}
#ctrl form#cb {
	float:right;
}
#ctrl form input,
#ctrl form label {
	padding:0;
	margin:0;
	vertical-align:middle;
	line-height:25px;
}
#ctrl form input {
	margin:0 3px 0 5px;
}
#ctrl form#cb label{
	font-size:11px;
}
#ctrl form#cb input{
	margin:0 6px 0 2px;
}

 /*** Control-bar on the bottom of the window ***/
#footer {
	border-top:solid 1px black;
	position:fixed;
	bottom:0px;
	left:0;
	width:100%;
	height:25px;
	background-color:#D3D3D3;
	display:relative;
	overflow:hidden;
}
#footer ul {
	padding:2px 68px 0 12px;
	height:23px;
	font-size:10px;
	line-height:11px;
	vertical-align:middle;
	display:table-cell;
}
#footer ul li {
	display:inline-block;
	color:black;
}
#footer ul li:after  {
	padding:0 8px;
	content:"\25cf"; /* black circle */
}
#footer ul li:last-child:after {
	display:none;
}
#footer ul li.last-child:after{ /* IE 8 */
	display:none;
}
#footer ul li em {
	font-style:normal;
	font-weight:normal;
}
#footer ul li a {
	color:inherit;
	display:none;
}
#footer form {
	padding:0 7px 0 12px;
	white-space:nowrap;
	display:table-cell;
	height:25px;
	line-height:25px;
}
#footer form#cb {
	padding-right:12px;
	position:absolute;
	right:0;top:0;
}
#footer form > * {
	vertical-align:middle;
}
#footer form label{
	padding:0 5px 0 3px;
}
#footer form#cb label{
	font-size:12px;
	padding:0 3px 0 0;
}


@media print {
	body {
		padding: 0;
		counter-reset:page;
	}
	h2{
		page-break-after:avoid;
	}
	.hll td.code, <!-- /* Shrink blue HLL lines in printout */ -->
	.hll td.addr,
	.hll td.icnt,
	.hll td.iclk,
	.hll td.icpi,
	.hll td.icpi2 {
		font-size:12px;
		padding-top:1px;
	}
	td.cov {
		-webkit-print-color-adjust:exact; <!-- /* Google Chrome should also print the background (Up to at least v.22 Chrome has no setting in its GUI to print the background of web-pages) */ -->
	}
	table.t32-coverage tr + tr > td {
		border-top: solid 1px #D3D3D3;
	}
	table#t32-ListVar   tr + tr.module > td,
	table#t32-ListFunc  tr + tr.module > td,
	table#t32-ListGroup tr + tr.group  > td {
		border-top-color: black;
	}
	#t32-ListFunc-cap, #t32-ListLine-cap, #t32-ListVar-cap, #t32-list-cap {
		page-break-before:always;
	}
	#ctrl {
		display:none;
	}
	#footer {
		margin-bottom:0;
	}
}
</xsl:variable>


<xsl:variable name="jFixIE8">
	<!-- Help IE8, which does not know ":last-child" CSS selector -->
	<![CDATA[
		$(function(){
			$('table tr:last-child, table th:last-child, table td:last-child').addClass("last-child");
		});
	]]>
</xsl:variable>

<xsl:variable name="jFixIE7">
	<!-- Help IE7, whose in trouble with border-spacing, empty table cells, :first-child -->
	<![CDATA[
		$(function(){
			var h2cnt = 1;
			$('table').attr("cellspacing", 0);
			$('table td:empty').html("&#8203;");
			$('table tr:first-child, table th:first-child, table td:first-child').addClass("first-child");
			$('h2').each(function(){ $(this).prepend(String(h2cnt++)+". "); });
		});
	]]>
	<xsl:text disable-output-escaping="yes">/*]]&gt;*/</xsl:text>
</xsl:variable>

<xsl:strip-space elements="TRACE32" />
<xsl:strip-space elements="listing List.EXPORT mixed" />
<xsl:strip-space elements="marker BookMark.EXPORT" />
<xsl:strip-space elements="coverage COVerage.EXPORT.ListModule COVerage.EXPORT.ListGroup COVerage.EXPORT.ListFunc COVerage.EXPORT.ListLine COVerage.EXPORT.ListVar COVerage.EXPORT" />
<xsl:preserve-space elements="src mnemonic" />
<xsl:variable name="lf">
	<xsl:text>&#10;</xsl:text>
</xsl:variable>
<xsl:variable name="ok"    select="'ok'" />
<xsl:variable name="never" select="'never'" />
<xsl:variable name="incomplete" select="'incomplete'" />
<xsl:variable name="lowercase" select="'abcdefghijklmnopqrstuvwxyz'" />
<xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />
<xsl:variable name="badchar"   select="'().,; äöüÄÖÜ'" />
<xsl:variable name="goodchar"  select="'------aouAOU'" />
<xsl:variable name="bookmarks" select="/TRACE32/marker/BookMark.EXPORT" />
<xsl:variable name="list"      select="/TRACE32/listing/List.EXPORT" />
<xsl:variable name="haveCov"   select="boolean(count($list/mixed/hll/cov | $list/mixed/asm/cov))" />
<xsl:variable name="haveIstat" select="boolean(count($list/mixed/hll/count | $list/mixed/asm/count))" />

<xsl:template match="/">
	<xsl:variable name="title">
		<xsl:text>TRACE32</xsl:text>
		<xsl:for-each select="TRACE32/*">
			<xsl:choose>
				<xsl:when test="position() = 1"><xsl:text>: </xsl:text></xsl:when>
				<xsl:otherwise>                 <xsl:text>, </xsl:text></xsl:otherwise>
			</xsl:choose>
			<xsl:choose>
				<xsl:when test="name() = 'marker'"  >
					<xsl:text>Bookmarks</xsl:text>
				</xsl:when>
				<xsl:when test="name() = 'listing'" >
					<xsl:text>List</xsl:text>
				</xsl:when>
				<xsl:when test="name() = 'coverage'">
					<xsl:for-each select="*">
						<xsl:if test="position() != 1"><xsl:text>, </xsl:text></xsl:if>
						<xsl:value-of select="substring(name(),17)"/>
					</xsl:for-each>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="name()"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:for-each>
	</xsl:variable>

	<html>
		<xsl:copy-of select="$lf" />
		<xsl:comment>
			This HTML file accepts the following GET paramters via JavaScript
			mode=mix/hll/asm  : Display Listing immediately in mixed, HLL or assembler view
			color=normal/gray : Use colors (normal) or paint in grayscale (gray)<xsl:copy-of select="$lf" /></xsl:comment>
		<xsl:copy-of select="$lf" />
		<head>
			<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
			<title><xsl:copy-of select="$title"/></title>
			<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
			<!-- <meta http-equiv="content-type" content="text/html; charset=ISO-8859-1"/> -->
			<meta http-equiv="content-language" content="en" />
			<meta name="generator">
				<xsl:attribute name="content"><xsl:value-of select="system-property('xsl:vendor')" /></xsl:attribute>
			</meta>
			<meta content="IE=edge" http-equiv="X-UA-Compatible" /><!-- Push IE always to highest rendering engine -->
			<!-- <link rel="stylesheet" type="text/css" href="style.css"/> -->
			<!-- <script type="text/javascript" src="jquery-1.9.0.min.js"></script> -->
			<!-- <script type="text/javascript" src="jaction.js"></script> -->
			<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
			<style type="text/css">
				<xsl:copy-of select="normalize-space($style)" />
			</style>
			<script src="jquery.min.js"></script> 
			<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
			<script src="t32report.js"></script> 
			<xsl:comment><![CDATA[[if lte IE 8]><script type="text/javascript">]]><xsl:copy-of select="normalize-space($jFixIE8)"/><![CDATA[</script><![endif]]]></xsl:comment>
			<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
			<xsl:comment><![CDATA[[if lte IE 7]><script type="text/javascript">]]><xsl:copy-of select="normalize-space($jFixIE7)"/><![CDATA[</script><![endif]]]></xsl:comment>
			<xsl:copy-of select="$lf" />
		</head>
		<xsl:copy-of select="$lf" />
		<body>
			<xsl:copy-of select="$lf" />
			<xsl:comment><![CDATA[[if lte IE 6]><p style="color:red">You are using Internet Explorer 6 (or earlier), which is not supported!</p><![endif]]]></xsl:comment>
			<xsl:copy-of select="$lf" />
			<xsl:apply-templates />
			<div id="footer">
				<hr/>
				<ul>
					<li>
						<em>Timestamp: </em>
						<span class="ts">
							<xsl:value-of select="(descendant::*[@ts!=''])[1]/@ts" /><!-- take the timestamp from the first element with a timestamp -->
						</span>
					</li>
					<li><em>CPU Family: </em><xsl:value-of select="(descendant::*[@t32pv!=''])[1]/@t32pv" /></li>
					<li><em>PowerView: </em><xsl:value-of select="(descendant::*[@t32ver!=''])[1]/@t32ver" /></li>
					<li>
						<em>XSLT Proc.: </em>
						<xsl:value-of select="system-property('xsl:vendor')"/><xsl:text> </xsl:text>
						<a>
							<xsl:attribute name="href"><xsl:value-of select="system-property('xsl:vendor-url')"/></xsl:attribute>
							<xsl:text>(</xsl:text>
							<xsl:value-of select="system-property('xsl:vendor-url')"/>
							<xsl:text>)</xsl:text>
						</a>
						<xsl:text> v</xsl:text><xsl:value-of select="system-property('xsl:version')" />
					</li>
				</ul>
			</div><xsl:copy-of select="$lf" />
		</body>
		<xsl:copy-of select="$lf" />
	</html>
</xsl:template>


<xsl:template match="TRACE32">
	<h1>TRACE32 Export</h1>
	<xsl:copy-of select="$lf" />
	<ol id="toc">
		<xsl:if test="$list">
			<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
			<li><a href="#filelist-cap">Table of source files</a></li>
		</xsl:if>
		<xsl:for-each select="*">
			<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
			<xsl:choose>
				<xsl:when test="name() = 'marker'"  >
					<li><a href="#t32-bookmarks-cap">BookMarks</a></li>
				</xsl:when>
				<xsl:when test="name() = 'listing'" >
					<li><a href="#t32-list-cap">List</a></li>
				</xsl:when>
				<xsl:when test="name() = 'coverage'">
					<xsl:for-each select="*">
						<xsl:if test="position() != 1"><xsl:copy-of select="$lf" /><xsl:text>	</xsl:text></xsl:if>
						<li>
							<a>
								<xsl:attribute name="href">#t32-<xsl:value-of select="substring(name(),17)"/>-cap</xsl:attribute>
								<xsl:text>COVerage.</xsl:text>
								<xsl:value-of select="substring(name(),17)"/>
							</a>
						</li>
					</xsl:for-each>
				</xsl:when>
				<xsl:when test="name()='script' and system-property('xsl:vendor')='Transformiix'">
					<!--workaround for FireFox which finds a script node for some reason, when XML file was loaded via a webserver -->
				</xsl:when>
				<xsl:otherwise>
					<li>
						<a>
							<xsl:attribute name="href">#<xsl:value-of select="name()"/></xsl:attribute>
							<xsl:value-of select="name()"/>
						</a>
					</li>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:for-each>
		<xsl:copy-of select="$lf" />
	</ol>
	<xsl:copy-of select="$lf" />

	<!-- Show a list of all source-files: -->
	<xsl:if test="listing/List.EXPORT">
		<h2 id="filelist-cap">Table of source files</h2>
		<xsl:copy-of select="$lf" />
		<table id="filelist">
			<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
			<thead>
				<tr>
					<th class="addr">address</th>
					<th>source file</th>
				</tr>
			</thead>
			<tbody>
				<xsl:for-each select="listing/List.EXPORT/mixed">
					<xsl:variable name="previous" select="preceding-sibling::mixed[1]/@module" />
					<xsl:if test="boolean(@module) and normalize-space(@module)!='' and (@module!=$previous or not($previous))">
						<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
						<tr>
							<td class="addr">
								<xsl:value-of select="asm/addr"/>
							</td>
							<td>
								<xsl:call-template name="templ_LineLink" >
									<xsl:with-param name="text"  select="@module"/>
									<xsl:with-param name="fname" select="@module" />
									<xsl:with-param name="fline" select="'0'"/>
								</xsl:call-template>
							</td>
						</tr>
					</xsl:if>
				</xsl:for-each>
			</tbody>
			<xsl:copy-of select="$lf" />
		</table>
		<xsl:copy-of select="$lf" />
	</xsl:if>

	<!-- Go through all main tags in theire order: -->
	<xsl:apply-templates />

</xsl:template>


<xsl:template match="marker">
	<h2 id="t32-bookmarks-cap">BookMarks</h2><xsl:copy-of select="$lf" />
	<table id="t32-bookmarks"><xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
		<thead>
			<tr>
				<th class="bmname">bookmark</th>
				<th class="addr"  >address</th>
				<th class="sym"   >symbol</th>
				<th class="src"   >source file</th>
				<th class="line"  >line</th>
				<th class="remark">comment / justification</th>
			</tr>
		</thead>
		<tbody>
			<xsl:apply-templates />
		</tbody>
		<xsl:copy-of select="$lf" />
	</table>
	<xsl:copy-of select="$lf" />
</xsl:template>


<xsl:template match="BookMark.EXPORT/bookmark">
	<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
	<xsl:variable name="felf"><xsl:value-of select="concat('\\',substring-before(substring-after(sym,'\\'),'\'),'\')"/></xsl:variable>
	<xsl:variable name="fmodule"><xsl:value-of select="substring-before(substring-after(sym,$felf),'\')"/></xsl:variable>
	<xsl:variable name="fsrc"><xsl:value-of select="substring-after(src,'&quot;\')"/></xsl:variable>
	<xsl:variable name="fname">
		<xsl:value-of select="concat($felf,$fmodule,'\',$fsrc)"/>
	</xsl:variable>
	<tr class="bm">
		<xsl:attribute name="id">b.<xsl:value-of select="normalize-space(translate(name,$badchar,$goodchar))"/></xsl:attribute>
		<!-- <xsl:attribute name="data-mod"><xsl:value-of select="src"/></xsl:attribute> -->
		<td class="bmname">
			<xsl:value-of select="name"/>
		</td>
		<td class="addr">
			<xsl:value-of select="addr"/>
		</td>
		<td class="sym"><xsl:value-of select="sym" /></td>
		<td class="src">
			<xsl:call-template name="templ_LineLink" >
				<xsl:with-param name="text"  select="src"/>
				<xsl:with-param name="fname" select="$fname"/>
				<xsl:with-param name="fline" select="'0'"/>
			</xsl:call-template>
		</td>
		<td class="line">
			<xsl:call-template name="templ_LineLink" >
				<xsl:with-param name="text"  select="line"/>
				<xsl:with-param name="fname" select="$fname" />
				<xsl:with-param name="fline" select="line"/>
			</xsl:call-template>
		</td>
		<td class="remark"><xsl:value-of select="remark"/></td>
	</tr>
</xsl:template>


<xsl:template match="listing">
	<h2 id="t32-list-cap">List</h2><xsl:copy-of select="$lf" />
	<table id="t32-list">
		<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
		<thead>
			<tr>
				<xsl:if test="$haveCov">
					<th class="cov" >Coverage</th>
				</xsl:if>
				<xsl:if test="$haveIstat">
					<th class="icnt">Cnt</th>
					<th class="iclk">Clocks</th>
					<th class="icpi" colspan="2">CPI</th>
				</xsl:if>
				<th class="addr"  >Addr/Line</th>
				<th class="code"  >Code</th>
				<th class="label" >Label</th>
				<th class="mnemo" >Mnemonics</th>
				<th class="remark">Comment/Justification</th>
			</tr>
		</thead>
		<tbody>
			<xsl:apply-templates />
		</tbody>
		<xsl:copy-of select="$lf" />
	</table>
	<xsl:copy-of select="$lf" />
</xsl:template>


<xsl:template match="List.EXPORT/mixed">
	<xsl:variable name="previous" select="preceding-sibling::mixed[1]/@module" />
	<xsl:if test="boolean(@module) and normalize-space(@module)!='' and (@module!=$previous or not($previous))">
		<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
		<tr class="srcfile">
			<xsl:call-template name="templ_LineID" >
				<xsl:with-param name="fname" select="@module" />
			</xsl:call-template>
			<xsl:if test="$haveCov">
				<td class="cov" ></td>
			</xsl:if>
			<xsl:if test="$haveIstat">
				<td class="icnt"></td>
				<td class="iclk"></td>
				<td class="icpi" colspan="2"></td>
			</xsl:if>
			<td class="addr"></td>
			<td class="src" colspan="4">
				<a href="#filelist-cap"><xsl:value-of select="@module"/></a>
			</td>
		</tr>
	</xsl:if>
	<xsl:apply-templates />
</xsl:template>


<xsl:template match="hll">
	<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
	<xsl:variable name="myline" select="line" />
	<xsl:variable name="mybm"   select="$bookmarks/bookmark[line=$myline]" />
	<xsl:variable name="havebm" select="$mybm and $mybm/remark" />
	<tr>
		<xsl:attribute name="class">
			<xsl:text>hll </xsl:text>
			<xsl:choose>
				<xsl:when test="boolean(cov)"> <!--  This HLL line has a coverage state ?  -->
					<xsl:text>cov_</xsl:text>
					<xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
				</xsl:when>
				<xsl:when test="$haveCov"> <!--  The List contains coverage information ? -->
					<xsl:text>nocov_</xsl:text>
					<xsl:call-template name="cov_class"><xsl:with-param name="cov" select="../hll[last()]/cov"/></xsl:call-template>
				</xsl:when>
			</xsl:choose>
		</xsl:attribute>

		<xsl:if test="boolean(line)">
			<xsl:call-template name="templ_LineID" >
				<xsl:with-param name="fname" select="../@module" />
				<xsl:with-param name="fline" select="line"/>
			</xsl:call-template>
		</xsl:if>

		<xsl:if test="$haveCov">
			<td class="cov"><xsl:apply-templates select="cov" /></td>
		</xsl:if>

		<xsl:if test="$haveIstat">
			<td class="icnt" >
				<xsl:if test="count=0"><xsl:attribute name="class">icnt cov_never</xsl:attribute></xsl:if>
				<xsl:value-of select="count"/>
			</td>
			<td class="iclk" ><xsl:value-of select="clocks"/></td>
			<td class="icpi" ><xsl:value-of select="substring-before(cpi,'.')"/></td>
			<td class="icpi2">
				<xsl:if test="number(cpi)">
					<xsl:text>.</xsl:text>
					<xsl:value-of select="substring(concat(substring-after(ncpi,'.'),'00'),1,2)"/>
				</xsl:if>
			</td>
		</xsl:if>

		<td class="addr">
			<xsl:attribute name="title"><xsl:value-of select="../@module"/> : <xsl:value-of select="line"/></xsl:attribute>
			<xsl:value-of select="line"/>
		</td>

		<td colspan="3" class="code">
			<xsl:if test="not($havebm)"><xsl:attribute name="colspan">4</xsl:attribute></xsl:if>
			<xsl:if test="boolean(../asm[1]/label) and normalize-space(../asm[1]/label)!=''">
				<xsl:variable name="myLabel"  select="substring-before(../asm[1]/label,':')" />
				<xsl:if test="contains(src,$myLabel) or (starts-with($myLabel,'_') and contains(src,substring($myLabel,2)))">
					<a>
						<xsl:attribute name="name">
							<xsl:text>f.</xsl:text>
							<xsl:choose>
								<xsl:when test="starts-with($myLabel,'_')">
									<xsl:copy-of select="substring($myLabel,2)" />
								</xsl:when>
								<xsl:otherwise>
									<xsl:copy-of select="$myLabel" />
								</xsl:otherwise>
							</xsl:choose>
						</xsl:attribute>
					</a>
				</xsl:if>
			</xsl:if>
			<xsl:value-of select="src"/><xsl:text>&#160;</xsl:text>
		</td>
		<xsl:if test="$havebm">
			<td>
				<xsl:attribute name="class">remark</xsl:attribute>
				<xsl:attribute name="title">Bookmark: <xsl:value-of select="$mybm/name"/></xsl:attribute>
				<xsl:if test="normalize-space($mybm/addr)!=''">
					<xsl:attribute name="class">remark hllonly</xsl:attribute>
					<span class="addr"><xsl:value-of select="$mybm/addr"/></span>
				</xsl:if>
				<a>
					<xsl:attribute name="href">#b.<xsl:value-of select="normalize-space(translate($mybm/name,$badchar,$goodchar))"/></xsl:attribute>
					<xsl:value-of select="$mybm/remark"/>
				</a>
			</td>
		</xsl:if>
	</tr>
</xsl:template>


<xsl:template match="asm">
	<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
	<xsl:variable name="myaddr" select="translate(substring-after(addr,':'),$lowercase,$uppercase)" />
	<xsl:variable name="mybm"   select="$bookmarks/bookmark[translate(substring-after(addr,':'),$lowercase,$uppercase)=$myaddr]" />
	<xsl:variable name="havebm" select="$mybm and $mybm/remark" />
	<tr>
		<xsl:attribute name="class">
			<xsl:text>asm cov_</xsl:text>
			<xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
		</xsl:attribute>
		<xsl:attribute name="id">
			<xsl:text>x</xsl:text>
			<xsl:call-template name="templ_StripLeadingZeros" ><xsl:with-param name="text" select="$myaddr"/></xsl:call-template>
		</xsl:attribute>

		<xsl:if test="$haveCov">
			<td class="cov"><xsl:apply-templates select="cov" /></td>
		</xsl:if>

		<xsl:if test="$haveIstat">
			<td class="icnt">
				<xsl:if test="count=0"><xsl:attribute name="class">icnt cov_never</xsl:attribute></xsl:if>
				<xsl:value-of select="count" />
			</td>
			<td class="iclk" ><xsl:value-of select="clocks"/></td>
			<td class="icpi" ><xsl:value-of select="substring-before(cpi,'.')"/></td>
			<td class="icpi2">
				<xsl:if test="number(cpi)">
					<xsl:text>.</xsl:text>
					<xsl:value-of select="substring(concat(substring-after(cpi,'.'),'00'),1,2)"/>
				</xsl:if>
			</td>
		</xsl:if>

		<td class="addr" ><xsl:value-of select="addr" /></td>
		<td class="code">
			<xsl:variable name="len" select="string-length(code)" />
			<xsl:value-of select="substring(code, 1,2)"/>
			<xsl:if test="$len> 2"><xsl:text> </xsl:text><xsl:value-of select="substring(code, 3,2)"/></xsl:if>
			<xsl:if test="$len> 4"><xsl:text> </xsl:text><xsl:value-of select="substring(code, 5,2)"/></xsl:if>
			<xsl:if test="$len> 6"><xsl:text> </xsl:text><xsl:value-of select="substring(code, 7,2)"/></xsl:if>
			<xsl:if test="$len> 8"><xsl:text> </xsl:text><xsl:value-of select="substring(code, 9,2)"/></xsl:if>
			<xsl:if test="$len>10"><xsl:text> </xsl:text><xsl:value-of select="substring(code,11,2)"/></xsl:if>
			<xsl:if test="$len>12"><xsl:text> </xsl:text><xsl:value-of select="substring(code,13,2)"/></xsl:if>
			<xsl:if test="$len>14"><xsl:text> </xsl:text><xsl:value-of select="substring(code,15,2)"/></xsl:if>
		</td>
		<td class="label"><xsl:value-of select="label"/></td>
		<td class="mnemo">
			<xsl:if test="not($havebm)"><xsl:attribute name="colspan">2</xsl:attribute></xsl:if>
			<xsl:value-of select="mnemonic"/>
		</td>
		<xsl:if test="$havebm">
			<td>
				<xsl:attribute name="class">remark</xsl:attribute>
				<xsl:attribute name="title">Bookmark: <xsl:value-of select="$mybm/name"/></xsl:attribute>
				<a>
					<xsl:attribute name="href">#b.<xsl:value-of select="normalize-space(translate($mybm/name,$badchar,$goodchar))"/></xsl:attribute>
					<xsl:attribute name="name">bm.<xsl:value-of select="normalize-space(translate($mybm/name,$badchar,$goodchar))"/></xsl:attribute>
					<xsl:value-of select="$mybm/remark"/>
				</a>
			</td>
		</xsl:if>
	</tr>
</xsl:template>


<xsl:template match="coverage/*">
	<h2>
		<xsl:attribute name="id">t32-<xsl:value-of select="substring(name(),17)"/>-cap</xsl:attribute>
		<xsl:text>COVerage.</xsl:text>
		<xsl:value-of select="substring(name(),17)"/>
	</h2>
	<xsl:copy-of select="$lf" />
	<table class="t32-coverage">
		<xsl:attribute name="id">t32-<xsl:value-of select="substring(name(),17)"/></xsl:attribute>
		<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
		<thead>
			<tr>
				<th class="addr">address</th>
				<th class="tree">tree</th>
				<th class="cov" >coverage</th>
				<xsl:choose>
					<xsl:when test="name()='COVerage.EXPORT.ListVar'">
						<th class="ratio">read</th>
						<th class="graph"><table><tr><td>0%</td><td>100%</td></tr></table></th>
						<th class="ratio">write</th>
						<th class="graph"><table><tr><td>0%</td><td>100%</td></tr></table></th>
						<th class="cnt"  >bytes</th>
						<th class="cnt"  >read</th>
						<th class="cnt"  >write</th>
					</xsl:when>
					<xsl:otherwise>
						<th class="ratio">executed</th>
						<th class="graph"><table><tr><td>0%</td><td>50%</td><td>100%</td></tr></table></th>
						<xsl:choose>
							<xsl:when test="boolean(//onlyexec) or boolean(//notexec)">
								<th class="ratio">conds</th>
							</xsl:when>
							<xsl:otherwise>
								<th class="ratio">branches</th>
							</xsl:otherwise>
						</xsl:choose>
						<th class="cnt"  >ok</th>
						<xsl:choose>
							<xsl:when test="boolean(//onlyexec) or boolean(//notexec)">
								<th class="cnt">only exec</th>
								<th class="cnt">not exec</th>
							</xsl:when>
							<xsl:otherwise>
								<th class="cnt">taken</th>
								<th class="cnt">not taken</th>
							</xsl:otherwise>
						</xsl:choose>
						<th class="cnt">never  </th>
						<th class="cnt">bytes  </th>
						<th class="cnt">bytesok</th>
					</xsl:otherwise>
				</xsl:choose>
			</tr>
		</thead>
		<tbody>
			<xsl:apply-templates />
		</tbody>
		<xsl:copy-of select="$lf" />
	</table>
	<xsl:copy-of select="$lf" />
</xsl:template>


<xsl:template match="group">
	<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
	<tr>
		<xsl:attribute name="class">
			<xsl:value-of select="name()"/>
			<xsl:text> cov_</xsl:text><xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
		</xsl:attribute>

		<xsl:call-template name="templ_addrRange" />

		<td class="tree">
			<xsl:value-of select="tree"/>
		</td>

		<xsl:call-template name="cov_exec_branches_bytes">
			<xsl:with-param name="item" select="."/>
		</xsl:call-template>
	</tr>
	<xsl:apply-templates select="item" />
</xsl:template>


<xsl:template match="total">
	<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
	<tr>
		<xsl:attribute name="class">
			<xsl:text>total cov_</xsl:text><xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
		</xsl:attribute>

		<xsl:variable name="addrFrom" select="../module[1]/addrFrom" />
		<xsl:variable name="addrTo"   select="../module[last()]/addrTo" />
		<td class="addr">
			<xsl:if test="boolean($addrFrom) and boolean($addrTo)">
				<xsl:value-of select="$addrFrom"/>
				<xsl:text>--</xsl:text>
				<xsl:value-of select="substring-after($addrTo,':')"/>
			</xsl:if>
		</td>

		<td class="tree"><xsl:text>total</xsl:text></td>

		<xsl:call-template name="cov_exec_branches_bytes">
			<xsl:with-param name="item" select="."/>
		</xsl:call-template>
	</tr>
	<xsl:apply-templates select="item" />
</xsl:template>


<xsl:template match="module">
	<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
	<tr>
		<xsl:attribute name="class">
			<xsl:value-of select="name()"/>
			<xsl:text> cov_</xsl:text><xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
		</xsl:attribute>

		<xsl:choose>
			<xsl:when test="name(..)='COVerage.EXPORT.ListVar' and addrFrom='none'">
				<td class="addr"><xsl:text>&#160;</xsl:text></td>
			</xsl:when>
			<xsl:otherwise>
				<xsl:call-template name="templ_addrRange" />
			</xsl:otherwise>
		</xsl:choose>

		<td class="tree">
			<xsl:variable name="tree"   select="tree" />
			<xsl:variable name="module" select="substring-after(tree,'\')" />
			<xsl:choose>
				<xsl:when test="name(..)='COVerage.EXPORT.ListModule' and (/TRACE32/coverage/COVerage.EXPORT.ListFunc/module[tree=$tree] or boolean(/TRACE32/coverage/COVerage.EXPORT.ListLine/module[tree=$tree]))">
					<a>
						<xsl:attribute name="name">m<xsl:value-of   select="translate($module,'\','.')"/></xsl:attribute>
						<xsl:attribute name="href">#mf<xsl:value-of select="translate($module,'\','.')"/></xsl:attribute>
						<xsl:value-of select="tree"/>
					</a>
				</xsl:when>
				<xsl:when test="(name(..)='COVerage.EXPORT.ListFunc' or name(..)='COVerage.EXPORT.ListLine') and boolean(/TRACE32/coverage/COVerage.EXPORT.ListModule)">
					<a>
						<xsl:attribute name="name">mf<xsl:value-of select="translate($module,'\','.')"/></xsl:attribute>
						<xsl:attribute name="href">#m<xsl:value-of select="translate($module,'\','.')"/></xsl:attribute>
						<xsl:value-of select="tree"/>
					</a>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="tree"/>
				</xsl:otherwise>
			</xsl:choose>
		</td>

		<xsl:choose>
			<xsl:when test="name(..)='COVerage.EXPORT.ListVar'">
				<xsl:call-template name="cov_read_write">
					<xsl:with-param name="item" select="."/>
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise>
				<xsl:call-template name="cov_exec_branches_bytes">
					<xsl:with-param name="item" select="."/>
				</xsl:call-template>
			</xsl:otherwise>
		</xsl:choose>
	</tr>
	<xsl:apply-templates select="function" />
	<xsl:apply-templates select="var" />
</xsl:template>


<xsl:template match="function | item">
	<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
	<tr>
		<xsl:attribute name="class">
			<xsl:value-of select="name()"/>
			<xsl:text> cov_</xsl:text><xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
		</xsl:attribute>

		<xsl:call-template name="templ_addrRange" />

		<td class="tree">
			<xsl:variable name="myLabel" select="tree" />
			<xsl:if test="name(../..)='COVerage.EXPORT.ListLine' and boolean(/TRACE32/coverage/COVerage.EXPORT.ListFunc)">
				<xsl:attribute name="id">fl.<xsl:value-of select="tree" /></xsl:attribute>
			</xsl:if>
			<xsl:choose>
				<xsl:when test="name(../..)='COVerage.EXPORT.ListFunc' and boolean(/TRACE32/coverage/COVerage.EXPORT.ListLine)">
					<a>
						<xsl:attribute name="href">#fl.<xsl:value-of select="tree" /></xsl:attribute>
						<xsl:value-of select="tree"/>
					</a>
				</xsl:when>
				<xsl:when test="name(../..)='COVerage.EXPORT.ListGroup' and not(contains(tree,'--')) and boolean(/TRACE32/coverage/COVerage.EXPORT.ListLine)">
					<a>
						<xsl:attribute name="href">#fl.<xsl:value-of select="normalize-space(tree)" /></xsl:attribute>
						<xsl:value-of select="normalize-space(tree)"/>
					</a>
				</xsl:when>
				<xsl:when test="boolean($list/mixed/asm[substring-before(label,':')=$myLabel])">
					<a>
						<xsl:attribute name="href">#f.<xsl:value-of select="tree" /></xsl:attribute>
						<xsl:value-of select="tree"/>
					</a>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="tree"/>
				</xsl:otherwise>
			</xsl:choose>
		</td>

		<xsl:call-template name="cov_exec_branches_bytes">
			<xsl:with-param name="item" select="."/>
		</xsl:call-template>
	</tr>
	<xsl:apply-templates select="line" />
</xsl:template>


<xsl:template match="line">
	<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
	<tr>
		<xsl:attribute name="class">
			<xsl:value-of select="name()"/>
			<xsl:text> cov_</xsl:text><xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
		</xsl:attribute>

		<xsl:call-template name="templ_addrRange" />

		<td class="tree">
			<xsl:variable name="fname"><xsl:value-of select="../../tree"/>\<xsl:value-of select="normalize-space(substring-before(tree,'\'))"/></xsl:variable>
			<xsl:call-template name="templ_LineLink" >
				<xsl:with-param name="text"  select="tree"/>
				<xsl:with-param name="fname" select="$fname" />
				<xsl:with-param name="fline" select="substring-before(substring-after(tree,'\'),'--')"/>
			</xsl:call-template>
		</td>

		<xsl:call-template name="cov_exec_branches_bytes">
			<xsl:with-param name="item" select="."/>
		</xsl:call-template>
	</tr>
	<xsl:apply-templates select="line" />
</xsl:template>


<xsl:template match="var">
	<xsl:copy-of select="$lf" /><xsl:text>	</xsl:text>
	<tr>
		<xsl:attribute name="class">
			<xsl:value-of select="name()"/>
			<xsl:text> cov_</xsl:text><xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
		</xsl:attribute>

		<xsl:call-template name="templ_addrRange" />

		<td class="tree"><xsl:value-of select="tree"/></td>

		<xsl:call-template name="cov_read_write">
			<xsl:with-param name="item" select="."/>
		</xsl:call-template>
	</tr>
</xsl:template>


<xsl:template name="cov">
	<xsl:choose>
		<xsl:when test=".='ok'">          <xsl:value-of select="$ok"/>         </xsl:when>
		<xsl:when test=".='readwrite'">   <xsl:value-of select="$ok"/>         </xsl:when>
		<xsl:when test=".='stmt+mc/dc'">  <xsl:value-of select="$ok"/>         </xsl:when>
		<xsl:when test=".='mc/dc'">       <xsl:value-of select="$ok"/>         </xsl:when>
		<xsl:when test=".='stmt+dc'">     <xsl:value-of select="$ok"/>         </xsl:when>
		<xsl:when test=".='dc'">          <xsl:value-of select="$ok"/>         </xsl:when>
		<xsl:when test=".='stmt+cc'">     <xsl:value-of select="$ok"/>         </xsl:when>
		<xsl:when test=".='cc'">          <xsl:value-of select="$ok"/>         </xsl:when>
		<xsl:when test=".='stmt'">        <xsl:value-of select="$ok"/>         </xsl:when>
		<xsl:when test=".='never'">       <xsl:value-of select="$never"/>      </xsl:when>
		<xsl:when test=".='incomplete'">  <xsl:value-of select="$incomplete"/> </xsl:when>
		<xsl:otherwise>                   <xsl:value-of select="."/>  </xsl:otherwise>
	</xsl:choose>
</xsl:template>


<xsl:template name="cov_class">
	<xsl:param name="cov"/>
	<xsl:choose>
		<xsl:when test="$cov='ok'">          <xsl:text>ok</xsl:text>      </xsl:when>
		<xsl:when test="$cov='readwrite'">   <xsl:text>ok</xsl:text>      </xsl:when>
		<xsl:when test="$cov='stmt+mc/dc'">  <xsl:text>ok</xsl:text>      </xsl:when>
		<xsl:when test="$cov='mc/dc'">       <xsl:text>ok</xsl:text>      </xsl:when>
		<xsl:when test="$cov='stmt+dc'">     <xsl:text>ok</xsl:text>      </xsl:when>
		<xsl:when test="$cov='dc'">          <xsl:text>ok</xsl:text>      </xsl:when>
		<xsl:when test="$cov='stmt+cc'">     <xsl:text>ok</xsl:text>      </xsl:when>
		<xsl:when test="$cov='cc'">          <xsl:text>ok</xsl:text>      </xsl:when>
		<xsl:when test="$cov='stmt'">        <xsl:text>ok</xsl:text>      </xsl:when>
		<xsl:when test="$cov='never'">       <xsl:text>never</xsl:text>   </xsl:when>
		<xsl:when test="$cov=''">            <xsl:text>empty</xsl:text>   </xsl:when>
		<xsl:when test="not($cov)">          <xsl:text>empty</xsl:text>   </xsl:when>
		<xsl:otherwise>                      <xsl:text>partial</xsl:text> </xsl:otherwise>
	</xsl:choose>
</xsl:template>


<xsl:template name="templ_StripLeadingZeros">
	<xsl:param name="text" />
	<xsl:choose>
		<xsl:when test="starts-with($text,'0')">
			<xsl:call-template name="templ_StripLeadingZeros" >
				<xsl:with-param name="text" select="substring($text,2)"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="$text" />
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>


<xsl:template name="templ_addrRange">
	<td class="addr">
		<xsl:if test="boolean(addrFrom)">
			<xsl:value-of select="addrFrom"/>
			<xsl:if test="boolean(addrTo)">
				<xsl:text>--</xsl:text>
				<xsl:value-of select="substring-after(addrTo,':')"/>
			</xsl:if>
		</xsl:if>
	</td>
</xsl:template>


<xsl:template name="templ_ratio">
	<xsl:param name="ratio"/>
	<td class="ratio">
		<xsl:value-of select="$ratio"/>
	</td>
	<td class="graph">
		<table><tr>
			<td>
				<xsl:if test="$ratio != '0.000%'">
					<xsl:attribute name="style">width:<xsl:value-of select="$ratio"/></xsl:attribute>
				</xsl:if>
			</td>
			<td></td>
		</tr></table>
	</td>
</xsl:template>


<xsl:template name="cov_exec_branches_bytes">
	<xsl:param name="item"/>

	<td class="cov" >
		<xsl:apply-templates select="$item/cov" />
	</td>

	<xsl:call-template name="templ_ratio">
		<xsl:with-param name="ratio" select="$item/exec"/>
	</xsl:call-template>

	<td class="ratio">
		<xsl:choose>
			<xsl:when test="boolean($item/conds)"   ><xsl:value-of select="$item/conds"   /></xsl:when>
			<xsl:when test="boolean($item/branches)"><xsl:value-of select="$item/branches"/></xsl:when>
			<xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
		</xsl:choose>
	</td>

	<td class="cnt"><xsl:value-of select="ok" /></td>
	<td class="cnt">
		<xsl:choose>
			<xsl:when test="boolean($item/onlyexec)"><xsl:value-of select="$item/onlyexec"/></xsl:when>
			<xsl:when test="boolean($item/taken)"   ><xsl:value-of select="$item/taken"   /></xsl:when>
			<xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
		</xsl:choose>
	</td>
	<td class="cnt">
		<xsl:choose>
			<xsl:when test="boolean($item/notexec)" ><xsl:value-of select="$item/notexec" /></xsl:when>
			<xsl:when test="boolean($item/nottaken)"><xsl:value-of select="$item/nottaken"/></xsl:when>
			<xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
		</xsl:choose>
	</td>
	<td class="cnt">
		<xsl:choose>
			<xsl:when test="boolean($item/never)"><xsl:value-of select="$item/never"/></xsl:when>
			<xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
		</xsl:choose>
	</td>

	<td class="cnt"><xsl:value-of select="$item/bytes"  /></td>
	<td class="cnt"><xsl:value-of select="$item/bytesok"/></td>
</xsl:template>


<xsl:template name="cov_read_write">
	<xsl:param name="item"/>

	<td class="cov"><xsl:apply-templates select="$item/cov" /></td>
	<xsl:call-template name="templ_ratio">
		<xsl:with-param name="ratio" select="$item/read"/>
	</xsl:call-template>
	<xsl:call-template name="templ_ratio">
		<xsl:with-param name="ratio" select="$item/write"/>
	</xsl:call-template>
	<td class="cnt"><xsl:value-of select="$item/bytes"  /></td>
	<td class="cnt"><xsl:value-of select="$item/bread"  /></td>
	<td class="cnt"><xsl:value-of select="$item/bwrite" /></td>
</xsl:template>


<xsl:variable name="srcIDbig">
	<xsl:for-each select="$list/mixed">
		<xsl:variable name="previous" select="preceding-sibling::mixed[1]/@module" />
		<xsl:if test="boolean(@module) and normalize-space(@module)!='' and (@module!=$previous or not($previous))">
			<id><xsl:copy-of select="@module" /><xsl:value-of select="position()" /></id>
		</xsl:if>
	</xsl:for-each>
</xsl:variable>

<xsl:variable name="srcID">
	<xsl:choose>
		<xsl:when test="function-available('msxsl:node-set')">
			<xsl:for-each select="msxsl:node-set($srcIDbig)/id">
				<id><xsl:copy-of select="@module" /><xsl:value-of select="position()" /></id>
			</xsl:for-each>
		</xsl:when>
		<xsl:when test="function-available('exslt:node-set')">
			<xsl:for-each select="exslt:node-set($srcIDbig)/id">
				<id><xsl:copy-of select="@module" /><xsl:value-of select="position()" /></id>
			</xsl:for-each>
		</xsl:when>
	</xsl:choose>
</xsl:variable>

<xsl:variable name="srcIDsimple">
	<xsl:text>|</xsl:text>
	<xsl:for-each select="$list/mixed">
		<xsl:variable name="previous" select="preceding-sibling::mixed[1]/@module" />
		<xsl:if test="boolean(@module) and normalize-space(@module)!='' and (@module!=$previous or not($previous))">
			<xsl:value-of select="@module"/><xsl:text>|</xsl:text>
		</xsl:if>
	</xsl:for-each>
</xsl:variable>

<xsl:template name="templ_fileID">
	<xsl:param name="fname" />
		<xsl:choose>
			<xsl:when test="function-available('msxsl:node-set')">
				<xsl:value-of select="msxsl:node-set($srcID)/id[@module=$fname]"/>
			</xsl:when>
			<xsl:when test="function-available('exslt:node-set')">
				<xsl:value-of select="exslt:node-set($srcID)/id[@module=$fname]"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="string-length(substring-before($srcIDsimple,$fname))" />
			</xsl:otherwise>
		</xsl:choose>
</xsl:template>


<xsl:template name="templ_LineID">
	<xsl:param name="fname" />
	<xsl:param name="fline" select="0" />
	<xsl:variable name="id">
		<xsl:call-template name="templ_fileID" >
			<xsl:with-param name="fname" select="$fname"/>
		</xsl:call-template>
	</xsl:variable>
	<xsl:if test="$id!='' or true()">
		<xsl:attribute name="id">l<xsl:value-of select="$id"/>.<xsl:value-of select="$fline"/></xsl:attribute>
	</xsl:if>
</xsl:template>


<xsl:template name="templ_LineLink">
	<xsl:param name="text"  />
	<xsl:param name="fname" />
	<xsl:param name="fline" />
	<xsl:variable name="id">
		<xsl:call-template name="templ_fileID" >
			<xsl:with-param name="fname" select="$fname"/>
		</xsl:call-template>
	</xsl:variable>
	<xsl:choose>
		<xsl:when test="$id!='' and normalize-space($fline)!=''">
			<a>
				<xsl:attribute name="href">#l<xsl:value-of select="$id"/>.<xsl:value-of select="$fline"/></xsl:attribute>
				<xsl:value-of select="$text" />
			</a>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="$text" />
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>


</xsl:stylesheet>