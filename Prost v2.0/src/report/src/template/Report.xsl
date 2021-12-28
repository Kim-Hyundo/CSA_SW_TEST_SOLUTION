<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:output method="html"/>

    <xsl:template match="/">

        <html>

            <body>

                <h2 style="text-align:center">Test Result</h2>

                <table border="1" style="width: 50%; margin: auto">
                    <tr>
                        <th>Test ID</th>
						<th>Input Data</th>
						<th>Expect Output Data</th>
						<th>Actual Output Data</th>
						<th>Pass/Fail</th>
						<th>Execution Time</th>
                    </tr>
					
					<xsl:for-each select="/testresult/count">
						<tr>
							<th><xsl:value-of select="testid"/></th>
							<th><xsl:value-of select="input"/></th>
							<th><xsl:value-of select="expectoutput"/></th>
							<th><xsl:value-of select="actualoutput"/></th>
							<th><xsl:value-of select="passfail"/></th>
							<th><xsl:value-of select="executiontime"/></th>
						</tr>
					</xsl:for-each>

                </table>

            </body>

        </html>

 

    </xsl:template>

</xsl:stylesheet>