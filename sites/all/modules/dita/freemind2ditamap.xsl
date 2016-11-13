<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  
  <xsl:output method="xml" indent="yes"/>
  <xsl:template match="map">
   <xsl:element name="map">
     <xsl:element name="title">
       <xsl:choose>
         <xsl:when test="*/@TEXT">
           <xsl:value-of select="normalize-space(*//@TEXT)"/>
         </xsl:when>
         <xsl:otherwise>
           <xsl:value-of select="normalize-space(*//FONT)"/>
         </xsl:otherwise>
       </xsl:choose>
     </xsl:element>
     <xsl:apply-templates select="/map/node/node"/>
  </xsl:element>
  </xsl:template>
  
  <xsl:template match="node/node">
    <xsl:if test="@TYPE='node'">
      <xsl:element name="topicref">
        <xsl:attribute name="href">
          <xsl:text>{dita_mindmap_title_placeholder-</xsl:text>
          <xsl:value-of select="attribute[@NAME='nid']/@VALUE"/>
          <xsl:text>}.dita</xsl:text>
        </xsl:attribute>
        <xsl:apply-templates select="node"/>
      </xsl:element>
    </xsl:if>
    <xsl:if test="@TYPE='normal'">
      <xsl:element name="topichead">
        <xsl:element name="topicmeta">
          <xsl:element name="navtitle">
            <xsl:choose>
              <xsl:when test="@TEXT">
                <xsl:value-of select="normalize-space(@TEXT)"/>
              </xsl:when>
              <xsl:otherwise>
                <xsl:value-of select="normalize-space(*//.)"/>
              </xsl:otherwise>
            </xsl:choose>
          </xsl:element>
        </xsl:element>
        <xsl:apply-templates select="node"/>
      </xsl:element>
    </xsl:if>        
  </xsl:template>
  
</xsl:stylesheet>

