<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:output method="html"/>

    <xsl:template match="/">

        <html>

            <body>

                <h2 style="text-align:center">Statistics</h2>

                <table border="1" style="width: 50%; margin: auto">
                    <tr>
                        <th>Test Sample Count</th>
						<th><xsl:value-of select="/statistics/testresult/count"/></th>
                        
                    </tr>
					<tr>
                        <th>Pass</th>
						<th><xsl:value-of select="/statistics/testresult/pass"/></th>				
                    </tr>
					<tr>
                        <th>Fail</th>
						<th><xsl:value-of select="/statistics/testresult/fail"/></th>
                    </tr>
					<tr>
                        <th>Max Execution Time</th>
						<th><xsl:value-of select="/statistics/testresult/maxtime"/></th>
                    </tr>
					<tr>
                        <th>Min Execution Time</th>
						<th><xsl:value-of select="/statistics/testresult/mintime"/></th>
                    </tr>
                </table>
				
				<h2 style="text-align:center">Memory Usage</h2>

                <table border="1" style="width: 50%; margin: auto">
					<th>Memory</th>
					<th>Code</th>
					<th>Data</th>
					<th>Reserved</th>
					<th>Free</th>
					<th>Total</th>
					<th>Usage</th>
					<xsl:for-each select="/statistics/memoryusage/area">
						<tr>
							<th><xsl:value-of select="name"/></th>
							<th><xsl:value-of select="code"/></th>
							<th><xsl:value-of select="data"/></th>
							<th><xsl:value-of select="reserved"/></th>
							<th><xsl:value-of select="free"/></th>
							<th><xsl:value-of select="total"/></th>
							<th><xsl:value-of select="usage"/></th>
						</tr>
					</xsl:for-each>
					
                </table>

            </body>

        </html>

 

    </xsl:template>

</xsl:stylesheet>