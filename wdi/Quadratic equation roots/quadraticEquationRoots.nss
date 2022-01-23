<!DOCTYPE nsscheme>
<nsscheme type="sequence">
  <position>
    <x>4</x>
    <y>30</y>
  </position>
  <size>
    <width>1104</width>
    <height>537</height>
  </size>
  <name>Obliczanie pierwiastków równania kwadratowego</name>
  <comment></comment>
  <author>Grzegorz Gil</author>
  <pascalCode contains="yes"/>
  <checkSyntax enabled="yes"/>
  <variables>
    <variable>
      <name>a</name>
      <type>
        <double/>
      </type>
      <value>1</value>
    </variable>
    <variable>
      <name>b</name>
      <type>
        <double/>
      </type>
      <value>4</value>
    </variable>
    <variable>
      <name>c</name>
      <type>
        <double/>
      </type>
      <value>3</value>
    </variable>
    <variable>
      <name>delta</name>
      <type>
        <double/>
      </type>
      <value>4</value>
    </variable>
    <variable>
      <name>root</name>
      <type>
        <double/>
      </type>
      <value>2.3342e-313</value>
    </variable>
    <variable>
      <name>root1</name>
      <type>
        <double/>
      </type>
      <value>-3</value>
    </variable>
    <variable>
      <name>root2</name>
      <type>
        <double/>
      </type>
      <value>-1</value>
    </variable>
  </variables>
  <sequence>
    <inputinstruction>
      <text>a</text>
      <comment>Podaj a:</comment>
    </inputinstruction>
    <inputinstruction>
      <text>b</text>
      <comment>Podaj b:</comment>
    </inputinstruction>
    <inputinstruction>
      <text>c</text>
      <comment>Podaj c:</comment>
    </inputinstruction>
    <selection instructionsheight="291" conditionheight="84">
      <condition>
        <text>a = 0</text>
        <comment></comment>
      </condition>
      <ontrue>
        <sequence>
          <outputinstruction>
            <text>'to nie jest funkcja kwadratowa'</text>
            <comment></comment>
          </outputinstruction>
        </sequence>
      </ontrue>
      <onfalse>
        <sequence>
          <simpleinstruction>
            <text>delta := b * b - 4 * a * c</text>
            <comment></comment>
          </simpleinstruction>
          <selection instructionsheight="204" conditionheight="59">
            <condition>
              <text>delta &lt; 0</text>
              <comment></comment>
            </condition>
            <ontrue>
              <sequence>
                <outputinstruction>
                  <text>'równanie nie ma pierwiastków'</text>
                  <comment></comment>
                </outputinstruction>
              </sequence>
            </ontrue>
            <onfalse>
              <sequence>
                <selection instructionsheight="154" conditionheight="44">
                  <condition>
                    <text>delta = 0</text>
                    <comment></comment>
                  </condition>
                  <ontrue>
                    <sequence>
                      <simpleinstruction>
                        <text>root := ((-1) * b - sqrt(delta)) / (2 * a)</text>
                        <comment></comment>
                      </simpleinstruction>
                      <outputinstruction>
                        <text>'równanie ma jeden pierwiastek: ', root</text>
                        <comment></comment>
                      </outputinstruction>
                    </sequence>
                  </ontrue>
                  <onfalse>
                    <sequence>
                      <simpleinstruction>
                        <text>root1 := ((-1) * b - sqrt(delta)) / (2 * a)</text>
                        <comment></comment>
                      </simpleinstruction>
                      <simpleinstruction>
                        <text>root2 := ((-1) * b + sqrt(delta)) / (2 * a)</text>
                        <comment></comment>
                      </simpleinstruction>
                      <outputinstruction>
                        <text>'równanie ma dwa pierwiastki: ', root1, root2</text>
                        <comment></comment>
                      </outputinstruction>
                    </sequence>
                  </onfalse>
                </selection>
              </sequence>
            </onfalse>
          </selection>
        </sequence>
      </onfalse>
    </selection>
  </sequence>
</nsscheme>
