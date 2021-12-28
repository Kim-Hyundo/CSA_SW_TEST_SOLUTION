<?xml version="1.0" encoding="ISO-8859-1"?>

<!--
__________________________________________________________________________________
@Title: XSLT stylesheet for hierarchic code coverage report
@Description:
 XSLT stylesheet for hierarchic code coverage report in multiple files.
@Author: HLG
@Keywords: coverage, XML, XSLT
@Copyright: (C) 1989-2017 Lauterbach GmbH, licensed for use with TRACE32(R) only
__________________________________________________________________________________
$Id: t32transform.xsl 14910 2019-09-10 09:37:21Z csax $
-->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html" media-type="text/html" indent="no" encoding="ISO-8859-1" omit-xml-declaration="yes"
            doctype-public="-//W3C//DTD HTML 4.01//EN"
            doctype-system="http://www.w3.org/TR/html4/strict.dtd" /> <!-- IE9 and newer preferes strict DTD -->
<!--
<xsl:output method="html" media-type="text/html" indent="no" encoding="ISO-8859-1" omit-xml-declaration="yes"
            doctype-public="-//W3C//DTD HTML 4.01 Transitional//EN"
            doctype-system="http://www.w3.org/TR/html4/loose.dtd" />
-->
<xsl:param name="style"   select="''" />
<xsl:param name="jquery"  select="''" />
<xsl:param name="jaction" select="''" />

<xsl:variable name="root_rellative">
  <xsl:choose>
    <xsl:when test="boolean(/TRACE32/coverage/COVerage.EXPORT.ListModule) and boolean(/TRACE32/listing/List.EXPORT)">../..</xsl:when>
    <xsl:when test="boolean(/TRACE32/coverage/COVerage.EXPORT.ListModule)">.</xsl:when>
    <xsl:otherwise>../..</xsl:otherwise>
  </xsl:choose>
</xsl:variable>

<xsl:strip-space elements="TRACE32" />
<xsl:strip-space elements="listing List.EXPORT mixed" />
<xsl:strip-space elements="marker BookMark.EXPORT" />
<xsl:strip-space elements="coverage COVerage.EXPORT.ListModule COVerage.EXPORT.ListGroup COVerage.EXPORT.ListFunc COVerage.EXPORT.ListLine COVerage.EXPORT.ListVar COVerage.EXPORT" />
<xsl:preserve-space elements="src mnemonic" />
<xsl:variable name="lf"><xsl:text>&#10;</xsl:text></xsl:variable>
<xsl:variable name="lftab"><xsl:text>&#10;&#9;</xsl:text></xsl:variable>
<xsl:variable name="ok"    select="'ok'" />
<xsl:variable name="never" select="'never'" />
<xsl:variable name="incomplete" select="'incomplete'" />
<xsl:variable name="lowercase" select="'abcdefghijklmnopqrstuvwxyz'" />
<xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />
<xsl:variable name="bookmarks" select="/TRACE32/marker/BookMark.EXPORT" />
<xsl:variable name="list"      select="/TRACE32/listing/List.EXPORT" />
<xsl:variable name="haveCov"   select="boolean(count($list/mixed/hll/cov | $list/mixed/asm/cov))" />
<xsl:variable name="haveDecisions"   select="boolean(count($list/mixed/hll/decisions | $list/mixed/asm/decisions))" />
<xsl:variable name="haveIstat" select="boolean(count($list/mixed/hll/count | $list/mixed/asm/count))" />
<xsl:variable name="copyright">
  <xsl:text disable-output-escaping="no">&#169;</xsl:text>
  <!-- <xsl:text disable-output-escaping="yes"><![CDATA[&copy;]]></xsl:text> -->
</xsl:variable>


<xsl:template match="/">
  <xsl:variable name="title">
    <xsl:text>TRACE32: </xsl:text>
    <xsl:value-of select="substring(name(TRACE32/coverage/*[1]),17)"/>
  </xsl:variable>

  <html>
    <xsl:copy-of select="$lf" />
    <head>
      <xsl:copy-of select="$lftab" />
      <title><xsl:copy-of select="$title"/></title>
      <xsl:copy-of select="$lftab" />
      <!-- <meta http-equiv="content-type" content="text/html; charset=ISO-8859-1"/> -->
      <meta http-equiv="content-language" content="en" />
      <xsl:copy-of select="$lftab" />
      <meta content="IE=edge" http-equiv="X-UA-Compatible" /><!-- Push IE always to highest rendering engine -->
      <xsl:copy-of select="$lftab" />
      <meta name="generator">
        <xsl:attribute name="content">
          <xsl:text>XSLT transformation by </xsl:text>
          <xsl:value-of select="system-property('xsl:vendor')" />
        </xsl:attribute>
      </meta>
      
      <xsl:copy-of select="$lftab" />
      <xsl:if test="$style!=''">
        <style type="text/css">
          <xsl:copy-of select="normalize-space($style)" />
        </style>
      </xsl:if>
      <xsl:if test="$style=''">
        <link rel="stylesheet" type="text/css">
          <xsl:attribute name="href">
            <xsl:value-of select="$root_rellative"/><xsl:text>/t32report.css</xsl:text>
          </xsl:attribute>
        </link>
      </xsl:if>

      <xsl:copy-of select="$lftab" />
      <script type="text/javascript">
        <xsl:if test="$jquery!=''">
          <xsl:copy-of select="normalize-space($jquery)" />
        </xsl:if>
        <xsl:if test="$jquery=''">
          <xsl:attribute name="src">
            <xsl:value-of select="$root_rellative"/><xsl:text>/jquery.min.js</xsl:text>
          </xsl:attribute>
        </xsl:if>
      </script>
      <xsl:copy-of select="$lftab" />
      <script type="text/javascript">
        <xsl:if test="$jaction!=''">
          <xsl:copy-of select="$jaction" />
          <xsl:copy-of select="$lftab" />
        </xsl:if>
        <xsl:if test="$jaction=''">
          <xsl:attribute name="src">
            <xsl:value-of select="$root_rellative"/><xsl:text>/t32report.js</xsl:text>
          </xsl:attribute>
        </xsl:if>
      </script>
      <xsl:copy-of select="$lf" />
    </head>
    <xsl:copy-of select="$lf" />
    <body>
      <xsl:copy-of select="$lf" />
      <xsl:comment><![CDATA[[if IE 8]><span id="IE8"></span><![endif]]]></xsl:comment>
      <xsl:copy-of select="$lf" />
      <xsl:comment><![CDATA[[if lte IE 7]><b id="oldIE">You are using Internet Explorer 7 (or earlier), which is not supported!</b><![endif]]]></xsl:comment>
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
  <div id="header" class="header">
    <h1>TRACE<span class="t32logo">32</span><sup><xsl:copy-of select="$copyright"/></sup> Code-Coverage Report</h1>
  </div><xsl:copy-of select="$lf" />
  <div id="content"><xsl:copy-of select="$lf" />
    <!-- Go through all main tags in theire order: -->
    <xsl:apply-templates />
  </div>
  <xsl:copy-of select="$lf" />
</xsl:template>


<xsl:template match="BookMark.EXPORT">
  <xsl:if test="boolean(bookmark) and position()=1">
    <div id="t32-bookmarks">
      <h2>
        <xsl:text>BookMark</xsl:text>
        <xsl:if test="count(bookmark)>1"><span class="plural">s</span></xsl:if>
      </h2>
      <table>
        <xsl:copy-of select="$lftab"/>
        <thead>
          <tr>
            <th class="bmname">bookmark</th>
            <th class="addr ascending">address</th>
            <th class="sym"   >symbol</th>
            <th class="src"   >source file</th>
            <th class="line"  >line</th>
            <th class="remark">comment / justification</th>
          </tr>
        </thead>
        <xsl:copy-of select="$lftab"/>
        <tbody>
          <xsl:call-template name="defaultattributes"/>
          <xsl:for-each select="self::*/bookmark|following-sibling::*/bookmark">
            <!-- cycle through all the bookmark tags and sort them by address -->
            <xsl:sort select="addr"/>
            <xsl:if test="not(preceding::bookmark[. = current()])"><!-- ignore dublicates -->
              <xsl:apply-templates select="." />
            </xsl:if>
          </xsl:for-each>
        </tbody>
        <xsl:copy-of select="$lf" />
      </table>
    </div>
    <xsl:copy-of select="$lf" />
  </xsl:if>
</xsl:template>


<xsl:template match="BookMark.EXPORT/bookmark">
  <tr class="bm">
    <td class="bmname">
      <xsl:value-of select="name"/>
    </td>
    <td class="addr">
      <xsl:value-of select="addr"/>
    </td>
    <td class="sym">
      <xsl:if test="sym/@func-uid">
        <xsl:attribute name="data-func-uid"><xsl:value-of select="sym/@func-uid"/></xsl:attribute>
      </xsl:if>
      <xsl:value-of select="sym"/>
    </td>
    <td class="src"><xsl:value-of select="src"/></td>
    <td class="line"><xsl:value-of select="line" /></td>
    <td class="remark"><xsl:value-of select="remark"/></td>
  </tr>
</xsl:template>


<xsl:template match="listing">
  <div id="t32-list">
    <h2>List</h2>
    <table>
      <xsl:copy-of select="$lftab" />
      <thead>
        <tr>
          <xsl:if test="$haveDecisions">
            <th class="dec" >Decisions</th>
            <th class="dec" >True</th>
            <th class="dec" >False</th>
                    </xsl:if>
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
          <th class="mnemo" colspan="2">Mnemonic</th>
          <th class="remark">Remark</th>
        </tr>
      </thead>
      <xsl:apply-templates />
      <xsl:copy-of select="$lf" />
    </table>
  </div>
  <xsl:copy-of select="$lf" />
</xsl:template>


<xsl:template match="List.EXPORT">
  <xsl:copy-of select="$lftab" />
  <tbody>
    <xsl:call-template name="defaultattributes"/>
    <xsl:apply-templates />
  </tbody>
</xsl:template>


<xsl:template match="List.EXPORT/mixed">
  <xsl:variable name="previous" select="preceding-sibling::mixed[1]/@module" />
  <xsl:if test="boolean(@module) and normalize-space(@module)!='' and (@module!=$previous or not($previous))">
    <xsl:copy-of select="$lftab" />
    <tr class="srcfile">
      <xsl:if test="$haveDecisions">
        <td class="dec" colspan="3"></td>
      </xsl:if>
      <xsl:if test="$haveIstat">
        <td class="icnt"></td>
        <td class="iclk"></td>
        <td class="icpi" colspan="2"></td>
      </xsl:if>
      <td class="addr" colspan="2">file</td>
      <td class="src" colspan="5">
        <xsl:value-of select="@module"/>
      </td>
    </tr>
  </xsl:if>
  <xsl:apply-templates />
</xsl:template>


<xsl:template match="hll">
  <xsl:copy-of select="$lftab" />
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
    <xsl:attribute name="data-module"><xsl:value-of select="../@module"/></xsl:attribute>

    <xsl:if test="$haveDecisions">
      <td class="dec"><xsl:apply-templates select="decisions" /></td>
      <td class="dec"><xsl:apply-templates select="true" /></td>
      <td class="dec"><xsl:apply-templates select="false" /></td>
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

    <td class="addr"><xsl:value-of select="line"/></td>

    <td colspan="4" class="code">
      <xsl:if test="not($havebm)"><xsl:attribute name="colspan">5</xsl:attribute></xsl:if>
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
        <xsl:value-of select="$mybm/remark"/>
      </td>
    </xsl:if>
  </tr>
</xsl:template>


<xsl:template match="asm">
  <xsl:copy-of select="$lftab" />
  <xsl:variable name="myaddr" select="translate(substring-after(addr,':'),$lowercase,$uppercase)" />
  <xsl:variable name="mybm"   select="$bookmarks/bookmark[translate(substring-after(addr,':'),$lowercase,$uppercase)=$myaddr]" />
  <xsl:variable name="havebm" select="$mybm and $mybm/remark" />

  <tr>
    <xsl:attribute name="class">
      <xsl:text>asm cov_</xsl:text>
      <xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
    </xsl:attribute>
    <xsl:attribute name="data-module"><xsl:value-of select="../@module"/></xsl:attribute>

    <xsl:if test="$haveDecisions">
      <td class="dec"><xsl:apply-templates select="decisions" /></td>
      <td class="dec"><xsl:apply-templates select="true" /></td>
      <td class="dec"><xsl:apply-templates select="false" /></td>
    </xsl:if>

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
      <xsl:value-of select="mnemonic"/>
    </td>
    
    <td class="comment">
      <xsl:if test="./comment">
        <i>
          <xsl:if test="comment">; </xsl:if>
          <xsl:value-of select="comment"/>
        </i>
      </xsl:if>
    </td>
    
    <td>
      <xsl:if test="$havebm">
        <xsl:attribute name="class">remark</xsl:attribute>
        <xsl:attribute name="title">Bookmark: <xsl:value-of select="$mybm/name"/></xsl:attribute>
        <xsl:value-of select="$mybm/remark"/>
      </xsl:if>
    </td>
  </tr>
</xsl:template>


<xsl:template match="coverage">
  <xsl:apply-templates select="COVerage.EXPORT.ListModule" />
  <xsl:apply-templates select="COVerage.EXPORT.ListFunc" />
  <xsl:apply-templates select="COVerage.EXPORT.ListLine" />
  <xsl:apply-templates select="COVerage.EXPORT.ListGroup" />
  <xsl:apply-templates select="COVerage.EXPORT.ListVar" />
</xsl:template>


<xsl:template name="t32-coverage-header">
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

          <xsl:if test="boolean(//exec[@metric='call'])">
            <th class="ratio">call</th>
            <th class="graph"><table><tr><td>0%</td><td>50%</td><td>100%</td></tr></table></th>
          </xsl:if>

          <xsl:if test="boolean(//exec[@metric='func'])">
            <th class="ratio">function</th>
            <th class="graph"><table><tr><td>0%</td><td>50%</td><td>100%</td></tr></table></th>
          </xsl:if>

          <xsl:if test="boolean(//exec[@metric='mcdc'])">
            <th class="ratio">mcdc</th>
            <th class="graph"><table><tr><td>0%</td><td>50%</td><td>100%</td></tr></table></th>
          </xsl:if>

          <xsl:if test="boolean(//exec[@metric='cond'])">
            <th class="ratio">condition</th>
            <th class="graph"><table><tr><td>0%</td><td>50%</td><td>100%</td></tr></table></th>
          </xsl:if>

          <xsl:if test="boolean(//exec[@metric='dec'])">
            <th class="ratio">decision</th>
            <th class="graph"><table><tr><td>0%</td><td>50%</td><td>100%</td></tr></table></th>
          </xsl:if>

          <xsl:if test="boolean(//exec[@metric='stmt'])">
            <th class="ratio">statement</th>
            <th class="graph"><table><tr><td>0%</td><td>50%</td><td>100%</td></tr></table></th>
          </xsl:if>

          <xsl:if test="boolean(//exec[@metric='object'])">
            <th class="ratio">objectcode</th>
            <th class="graph"><table><tr><td>0%</td><td>50%</td><td>100%</td></tr></table></th>
          </xsl:if>

          <xsl:choose>
            <xsl:when test="boolean(//branches) or boolean(//conds)">
              <xsl:choose>
                <xsl:when test="boolean(//onlyexec) or boolean(//notexec)">
                  <th class="ratio">conds</th>
                </xsl:when>
                <xsl:otherwise>
                  <th class="ratio">branches</th>
                </xsl:otherwise>
              </xsl:choose>
              <th class="ok"  >ok</th>
              <xsl:choose>
                <xsl:when test="boolean(//onlyexec) or boolean(//notexec)">
                  <th class="partial">only exec</th>
                  <th class="partial">not exec</th>
                </xsl:when>
                <xsl:otherwise>
                  <th class="partial">taken</th>
                  <th class="partial">not taken</th>
                </xsl:otherwise>
              </xsl:choose>
              <th class="never">never  </th>
            </xsl:when>
          </xsl:choose>

          <xsl:choose>
            <xsl:when test="boolean(//lines)">
              <th class="cnt">lines</th>
              <th class="ok">ok</th>
            </xsl:when>
          </xsl:choose>

          <xsl:choose>
            <xsl:when test="boolean(//functions)">
              <th class="cnt">functions</th>
              <th class="ok">ok</th>
            </xsl:when>
          </xsl:choose>

          <xsl:choose>
            <xsl:when test="boolean(//calls)">
              <th class="cnt">call</th>
              <th class="ok">ok</th>
            </xsl:when>
          </xsl:choose>

          <xsl:choose>
            <xsl:when test="boolean(//decisions)">
              <xsl:choose>
                <xsl:when test="boolean(//conditions)">
                  <th class="cnt">decisions</th>
                  <th class="ok">ok</th>
                  <th class="cnt">conditions</th>
                  <th class="cnt">true</th>
                  <th class="false">false</th>
                </xsl:when>
                <xsl:otherwise>
                  <th class="cnt">decisions</th>
                  <th class="cnt">true</th>
                  <th class="false">false</th>
                </xsl:otherwise>
              </xsl:choose>
            </xsl:when>
            <xsl:otherwise>
              <xsl:choose>
                <xsl:when test="boolean(//conditions)">
                  <th class="cnt">conditions</th>
                  <th class="cnt">true</th>
                  <th class="false">false</th>
                </xsl:when>
              </xsl:choose>
            </xsl:otherwise>
          </xsl:choose>

          <th class="cnt">bytes  </th>
          <th class="ok">bytesok</th>
        </xsl:otherwise>
      </xsl:choose>
    </tr>
  </thead>
</xsl:template>


<xsl:template match="coverage/*">
  <!--
    COVerage.EXPORT.ListModule
    COVerage.EXPORT.ListFunc
    COVerage.EXPORT.ListLine
    COVerage.EXPORT.ListGroup
    COVerage.EXPORT.ListVar
  -->
  <xsl:variable name="myname" select="name()" />
  <xsl:if test="count(preceding-sibling::*[name()=$myname])=0 and count(child::*[name()!='total'])>0">
    <!-- only the first of the same type -->
    <div>
      <xsl:attribute name="id">
        <xsl:text>t32-</xsl:text><xsl:value-of select="substring(name(),17)"/>
      </xsl:attribute>
      <h2>
        <xsl:text>COVerage.</xsl:text>
        <xsl:value-of select="substring(name(),17)"/>
      </h2>
      <xsl:copy-of select="$lf" />
      <table class="t32-coverage">
        <xsl:copy-of select="$lftab" />
        <xsl:call-template name="t32-coverage-header" />
        <xsl:for-each select="../*[name()=$myname]"><!-- for each of the same type -->
          <xsl:copy-of select="$lftab" />
          <tbody>
            <xsl:call-template name="defaultattributes"/>
            <xsl:apply-templates />
          </tbody>
        </xsl:for-each>
        <xsl:copy-of select="$lf" />
      </table>
    </div>
    <xsl:copy-of select="$lf" />
  </xsl:if>
</xsl:template>


<xsl:template match="total">
  <xsl:if test="not(name(..) = 'COVerage.EXPORT.ListFunc' or name(..) = 'COVerage.EXPORT.ListLine' or name(../..) = 'COVerage.EXPORT.ListLine')">
    <xsl:copy-of select="$lftab" />
    <tr>
      <xsl:attribute name="class">
        <xsl:text>total cov_</xsl:text>
        <xsl:call-template name="cov_class">
          <xsl:with-param name="cov" select="cov"/>
        </xsl:call-template>
      </xsl:attribute>

      <td class="addr"/>

      <td class="tree"><xsl:text>total</xsl:text></td>

      <xsl:call-template name="cells_coverage">
        <xsl:with-param name="item" select="."/>
      </xsl:call-template>

      <xsl:call-template name="cells_progress">
        <xsl:with-param name="item" select="."/>
      </xsl:call-template>

      <xsl:call-template name="cells_branches">
        <xsl:with-param name="item" select="."/>
      </xsl:call-template>

      <xsl:call-template name="cells_functions">
        <xsl:with-param name="item" select="."/>
      </xsl:call-template>

      <xsl:call-template name="cells_calls">
        <xsl:with-param name="item" select="."/>
      </xsl:call-template>

      <xsl:call-template name="cells_lines">
        <xsl:with-param name="item" select="."/>
      </xsl:call-template>

      <xsl:call-template name="cells_decisions">
        <xsl:with-param name="item" select="."/>
      </xsl:call-template>

      <xsl:call-template name="cells_conditions">
        <xsl:with-param name="item" select="."/>
      </xsl:call-template>

      <xsl:call-template name="cells_bytes">
        <xsl:with-param name="item" select="."/>
      </xsl:call-template>
    </tr>
    <xsl:apply-templates select="item" />
  </xsl:if>
</xsl:template>


<xsl:template match="module">
  <xsl:copy-of select="$lftab" />
  <tr>
    <xsl:attribute name="class">
      <xsl:value-of select="name()"/>
      <xsl:if test="position() = 1">
        <xsl:text> first_</xsl:text><xsl:value-of select="name()"/>
      </xsl:if>
      <xsl:text> cov_</xsl:text><xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
    </xsl:attribute>

    <xsl:choose>
      <xsl:when test="name(..)='COVerage.EXPORT.ListVar' and addrFrom='none'">
        <td class="addr"> </td>
      </xsl:when>
      <xsl:otherwise>
        <xsl:call-template name="templ_addrRange" />
      </xsl:otherwise>
    </xsl:choose>

    <td class="tree">
      <xsl:value-of select="tree"/>
    </td>

    <xsl:choose>
      <xsl:when test="name(..)='COVerage.EXPORT.ListVar'">
        <xsl:call-template name="cov_read_write">
          <xsl:with-param name="item" select="."/>
        </xsl:call-template>
      </xsl:when>
      <xsl:otherwise>
        <xsl:call-template name="cells_coverage">
          <xsl:with-param name="item" select="."/>
        </xsl:call-template>

        <xsl:call-template name="cells_progress">
          <xsl:with-param name="item" select="."/>
        </xsl:call-template>

        <xsl:call-template name="cells_branches">
          <xsl:with-param name="item" select="."/>
        </xsl:call-template>

        <xsl:call-template name="cells_functions">
          <xsl:with-param name="item" select="."/>
        </xsl:call-template>

        <xsl:call-template name="cells_calls">
          <xsl:with-param name="item" select="."/>
        </xsl:call-template>

        <xsl:call-template name="cells_lines">
          <xsl:with-param name="item" select="."/>
        </xsl:call-template>

        <xsl:call-template name="cells_decisions">
          <xsl:with-param name="item" select="."/>
        </xsl:call-template>

        <xsl:call-template name="cells_conditions">
          <xsl:with-param name="item" select="."/>
        </xsl:call-template>

        <xsl:call-template name="cells_bytes">
          <xsl:with-param name="item" select="."/>
        </xsl:call-template>
      </xsl:otherwise>
    </xsl:choose>
  </tr>
  <xsl:apply-templates select="function" />
  <xsl:apply-templates select="total" />
  <xsl:apply-templates select="var" />
</xsl:template>


<xsl:template match="function | item">
  <xsl:copy-of select="$lftab" />
  <tr>
    <xsl:attribute name="class">
      <xsl:value-of select="name()"/>
      <xsl:if test="position() = 1">
        <xsl:text> first_</xsl:text><xsl:value-of select="name()"/>
      </xsl:if>
      <xsl:text> cov_</xsl:text><xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
    </xsl:attribute>

    <xsl:attribute name="data-uid">
      <xsl:value-of select="tree/@uid"/>
    </xsl:attribute>

    <xsl:call-template name="templ_addrRange" />

    <td class="tree">
      <xsl:value-of select="tree"/>
    </td>

    <xsl:call-template name="cells_coverage">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_progress">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_branches">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_functions">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_calls">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_lines">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_decisions">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_conditions">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_bytes">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>
  </tr>
  <xsl:apply-templates select="line" />
  <xsl:apply-templates select="total" />
</xsl:template>


<xsl:template match="line">
  <xsl:copy-of select="$lftab" />
  <tr>
    <xsl:attribute name="class">
      <xsl:value-of select="name()"/>
      <xsl:if test="position() = 1">
        <xsl:text> first_</xsl:text><xsl:value-of select="name()"/>
      </xsl:if>
      <xsl:text> cov_</xsl:text><xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
    </xsl:attribute>
    <xsl:attribute name="data-module"><xsl:value-of select="../../tree"/></xsl:attribute>

    <xsl:call-template name="templ_addrRange" />

    <td class="tree">
      <xsl:value-of select="tree"/>
    </td>

    <xsl:call-template name="cells_coverage">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_progress">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_branches">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_functions">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_calls">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_lines">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_decisions">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_conditions">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>

    <xsl:call-template name="cells_bytes">
      <xsl:with-param name="item" select="."/>
    </xsl:call-template>
  </tr>
</xsl:template>


<xsl:template match="var">
  <xsl:copy-of select="$lftab" />
  <tr>
    <xsl:attribute name="class">
      <xsl:value-of select="name()"/>
      <xsl:text> cov_</xsl:text><xsl:call-template name="cov_class"><xsl:with-param name="cov" select="cov"/></xsl:call-template>
    </xsl:attribute>

    <xsl:call-template name="templ_addrRange" />

    <td class="tree">
      <xsl:value-of select="tree"/>
    </td>

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
    <xsl:when test=".='call'">        <xsl:value-of select="$ok"/>         </xsl:when>
    <xsl:when test=".='func'">        <xsl:value-of select="$ok"/>         </xsl:when>
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
    <xsl:when test="$cov='call'">        <xsl:text>ok</xsl:text>      </xsl:when>
    <xsl:when test="$cov='func'">        <xsl:text>ok</xsl:text>      </xsl:when>
    <xsl:when test="$cov='never'">       <xsl:text>never</xsl:text>   </xsl:when>
    <xsl:when test="$cov=''">            <xsl:text>empty</xsl:text>   </xsl:when>
    <xsl:when test="not($cov)">          <xsl:text>empty</xsl:text>   </xsl:when>
    <xsl:otherwise>                      <xsl:text>partial</xsl:text> </xsl:otherwise>
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


<xsl:template name="cells_ratio">
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


<xsl:template name="cells_coverage">
  <td class="cov" >
    <xsl:apply-templates select="./cov" />
  </td>
</xsl:template>


<xsl:template name="cells_progress">
    <xsl:choose>
      <xsl:when test="boolean(./exec)">
        <xsl:for-each select="./exec">
          <xsl:call-template name="cells_ratio">
            <xsl:with-param name="ratio" select="."/>
          </xsl:call-template>
        </xsl:for-each>
      </xsl:when>

      <xsl:otherwise>
          <xsl:if test="boolean(../module/exec[@metric='call'])">
            <td class="ratio"><xsl:text>?</xsl:text></td>
            <td class="graph"/>
          </xsl:if>

          <xsl:if test="boolean(../module/exec[@metric='func'])">
            <td class="ratio"><xsl:text>?</xsl:text></td>
            <td class="graph"/>
          </xsl:if>

          <xsl:if test="boolean(../module/exec[@metric='mcdc'])">
            <td class="ratio"><xsl:text>?</xsl:text></td>
            <td class="graph"/>
          </xsl:if>

          <xsl:if test="boolean(../module/exec[@metric='cond'])">
            <td class="ratio"><xsl:text>?</xsl:text></td>
            <td class="graph"/>
          </xsl:if>

          <xsl:if test="boolean(../module/exec[@metric='dec'])">
            <td class="ratio"><xsl:text>?</xsl:text></td>
            <td class="graph"/>
          </xsl:if>

          <xsl:if test="boolean(../module/exec[@metric='stmt'])">
            <td class="ratio"><xsl:text>?</xsl:text></td>
            <td class="graph"/>
          </xsl:if>

          <xsl:if test="boolean(../module/exec[@metric='object'])">
            <td class="ratio"><xsl:text>?</xsl:text></td>
            <td class="graph"/>
          </xsl:if>
      </xsl:otherwise>
    </xsl:choose>
</xsl:template>


<xsl:template name="cells_branches">
  <xsl:choose>
    <xsl:when test="boolean(//conds) or boolean(//branches)">
      <td class="ratio">
        <xsl:choose>
          <xsl:when test="boolean(./conds)"   ><xsl:value-of select="./conds"   /></xsl:when>
          <xsl:when test="boolean(./branches)"><xsl:value-of select="./branches"/></xsl:when>
          <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
        </xsl:choose>
      </td>
  
      <td class="ok">
        <xsl:choose>
          <xsl:when test="boolean(./ok)"><xsl:value-of select="./ok"/></xsl:when>
          <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
        </xsl:choose>
      </td>
      
      <td class="partial">
        <xsl:choose>
          <xsl:when test="boolean(./onlyexec)"><xsl:value-of select="./onlyexec"/></xsl:when>
          <xsl:when test="boolean(./taken)"   ><xsl:value-of select="./taken"   /></xsl:when>
          <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
        </xsl:choose>
      </td>
      <td class="partial">
        <xsl:choose>
          <xsl:when test="boolean(./notexec)" ><xsl:value-of select="./notexec" /></xsl:when>
          <xsl:when test="boolean(./nottaken)"><xsl:value-of select="./nottaken"/></xsl:when>
          <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
        </xsl:choose>
      </td>
      <td class="never">
        <xsl:choose>
          <xsl:when test="boolean(./never)"><xsl:value-of select="./never"/></xsl:when>
          <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
        </xsl:choose>
      </td>
    </xsl:when>
  </xsl:choose>
</xsl:template>


<xsl:template name="cells_functions">
  <xsl:comment>  <xsl:text>decisions</xsl:text>  </xsl:comment>
  
  <xsl:choose>
    <xsl:when test="boolean(//functions)">
      <td class="cnt">
        <xsl:choose>
          <xsl:when test="boolean(./functions)"><xsl:value-of select="./functions"/></xsl:when>
          <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
        </xsl:choose>
      </td>
      <td class="ok">
        <xsl:choose>
          <xsl:when test="boolean(./functionsok)"><xsl:value-of select="./functionsok"/></xsl:when>
          <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
        </xsl:choose>
      </td>
    </xsl:when>
  </xsl:choose>
</xsl:template>


<xsl:template name="cells_calls">
  <xsl:comment>  <xsl:text>decisions</xsl:text>  </xsl:comment>
  
  <xsl:choose>
    <xsl:when test="boolean(//calls)">
      <td class="cnt">
        <xsl:choose>
          <xsl:when test="boolean(./calls)"><xsl:value-of select="./calls"/></xsl:when>
          <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
        </xsl:choose>
      </td>
      <td class="ok">
        <xsl:choose>
          <xsl:when test="boolean(./callsok)"><xsl:value-of select="./callsok"/></xsl:when>
          <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
        </xsl:choose>
      </td>
    </xsl:when>
  </xsl:choose>
</xsl:template>


<xsl:template name="cells_lines">
  <xsl:choose>
    <xsl:when test="boolean(//lines)">
      <td class="cnt">
        <xsl:choose>
          <xsl:when test="boolean(./lines)"><xsl:value-of select="./lines"/></xsl:when>
          <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
        </xsl:choose>
      </td>
      <td class="ok">
        <xsl:choose>
          <xsl:when test="boolean(./linesok)"><xsl:value-of select="./linesok"/></xsl:when>
          <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
        </xsl:choose>
      </td>
    </xsl:when>
  </xsl:choose>
</xsl:template>


<xsl:template name="cells_decisions">
  <xsl:comment>  <xsl:text>decisions</xsl:text>  </xsl:comment>

  <xsl:if test="boolean(//decisions)">
    <td class="cnt">
      <xsl:choose>
        <xsl:when test="boolean(./decisions)"><xsl:value-of select="./decisions"/></xsl:when>
        <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
      </xsl:choose>
    </td>

    <xsl:choose>
      <xsl:when test="boolean(//conditions)">
        <td class="ok">
          <xsl:choose>
            <xsl:when test="boolean(./decisionsok)"><xsl:value-of select="./decisionsok"/></xsl:when>
            <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
          </xsl:choose>
        </td>
      </xsl:when>
      <xsl:otherwise>
        <td class="true">
          <xsl:choose>
            <xsl:when test="boolean(./true)"><xsl:value-of select="./true"/></xsl:when>
            <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
          </xsl:choose>
        </td>
        <td class="false">
          <xsl:choose>
            <xsl:when test="boolean(./false)"><xsl:value-of select="./false"/></xsl:when>
            <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
          </xsl:choose>
        </td>
      </xsl:otherwise>
    </xsl:choose>
</xsl:if>
</xsl:template>


<xsl:template name="cells_conditions">
  <xsl:comment>  <xsl:text>conditions</xsl:text>  </xsl:comment>

  <xsl:if test="boolean(//conditions)">
    <td class="cnt">
      <xsl:choose>
        <xsl:when test="boolean(./conditions)"><xsl:value-of select="./conditions"/></xsl:when>
        <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
      </xsl:choose>
    </td>
    <td class="true">
      <xsl:choose>
        <xsl:when test="boolean(./true)"><xsl:value-of select="./true"/></xsl:when>
        <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
      </xsl:choose>
    </td>
    <td class="false">
      <xsl:choose>
        <xsl:when test="boolean(./false)"><xsl:value-of select="./false"/></xsl:when>
        <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
      </xsl:choose>
    </td>
  </xsl:if>
</xsl:template>


<xsl:template name="cells_bytes">
  <td class="cnt">
    <xsl:choose>
      <xsl:when test="boolean(./bytes)"><xsl:value-of select="./bytes"/></xsl:when>
      <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
    </xsl:choose>
  </td>
  <td class="ok">
    <xsl:choose>
      <xsl:when test="boolean(./bytesok)"><xsl:value-of select="./bytesok"/></xsl:when>
      <xsl:otherwise><xsl:text>?</xsl:text></xsl:otherwise>
    </xsl:choose>
  </td>
</xsl:template>


<xsl:template name="cov_read_write">
  <xsl:param name="item"/>

  <td class="cov"><xsl:apply-templates select="$item/cov" /></td>
  <xsl:call-template name="cells_ratio">
    <xsl:with-param name="ratio" select="$item/read"/>
  </xsl:call-template>
  <xsl:call-template name="cells_ratio">
    <xsl:with-param name="ratio" select="$item/write"/>
  </xsl:call-template>
  <td class="cnt"><xsl:value-of select="$item/bytes"  /></td>
  <td class="cnt"><xsl:value-of select="$item/bread"  /></td>
  <td class="cnt"><xsl:value-of select="$item/bwrite" /></td>
</xsl:template>


<xsl:template name="defaultattributes">
  <xsl:attribute name="data-ts"><xsl:value-of select="@ts"/></xsl:attribute>
  <xsl:attribute name="data-t32ver"><xsl:value-of select="@t32ver"/></xsl:attribute>
  <xsl:attribute name="data-t32pv"><xsl:value-of select="@t32pv"/></xsl:attribute>
</xsl:template>

</xsl:stylesheet>
