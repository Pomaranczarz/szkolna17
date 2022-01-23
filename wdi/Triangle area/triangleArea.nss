<!DOCTYPE nsscheme>
<nsscheme type="sequence">
  <position>
    <x>4</x>
    <y>30</y>
  </position>
  <size>
    <width>1212</width>
    <height>464</height>
  </size>
  <name>Obliczanie pola trójkąta</name>
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
      <value>2.061e-312</value>
    </variable>
    <variable>
      <name>b</name>
      <type>
        <double/>
      </type>
      <value>1.6022e-306</value>
    </variable>
    <variable>
      <name>c</name>
      <type>
        <double/>
      </type>
      <value>2.10344e-312</value>
    </variable>
    <variable>
      <name>p</name>
      <type>
        <double/>
      </type>
      <value>8.01048e-307</value>
    </variable>
    <variable>
      <name>s</name>
      <type>
        <double/>
      </type>
      <value>7.00303e-313</value>
    </variable>
  </variables>
  <sequence>
    <inputinstruction>
      <text>a</text>
      <comment>Podaj bok a:</comment>
    </inputinstruction>
    <inputinstruction>
      <text>b</text>
      <comment>Podaj bok b:</comment>
    </inputinstruction>
    <inputinstruction>
      <text>c</text>
      <comment>Podaj bok c:</comment>
    </inputinstruction>
    <selection instructionsheight="234" conditionheight="68">
      <condition>
        <text>a + b > c</text>
        <comment></comment>
      </condition>
      <ontrue>
        <sequence>
          <selection instructionsheight="177" conditionheight="51">
            <condition>
              <text>a + c > b</text>
              <comment></comment>
            </condition>
            <ontrue>
              <sequence>
                <selection instructionsheight="133" conditionheight="38">
                  <condition>
                    <text>b + c > a</text>
                    <comment></comment>
                  </condition>
                  <ontrue>
                    <sequence>
                      <simpleinstruction>
                        <text>p := 0.5 * (a + b + c)</text>
                        <comment></comment>
                      </simpleinstruction>
                      <simpleinstruction>
                        <text>s := sqrt(p * (p - a) * (p - b) * (p - c))</text>
                        <comment></comment>
                      </simpleinstruction>
                      <outputinstruction>
                        <text>'pole = ', s</text>
                        <comment></comment>
                      </outputinstruction>
                    </sequence>
                  </ontrue>
                  <onfalse>
                    <sequence>
                      <outputinstruction>
                        <text>'Z podanych boków nie można utworzyć trójkąta'</text>
                        <comment></comment>
                      </outputinstruction>
                    </sequence>
                  </onfalse>
                </selection>
              </sequence>
            </ontrue>
            <onfalse>
              <sequence>
                <outputinstruction>
                  <text>'Z podanych boków nie można utworzyć trójkąta'</text>
                  <comment></comment>
                </outputinstruction>
              </sequence>
            </onfalse>
          </selection>
        </sequence>
      </ontrue>
      <onfalse>
        <sequence>
          <outputinstruction>
            <text>'Z podanych boków nie można utworzyć trójkąta'</text>
            <comment></comment>
          </outputinstruction>
        </sequence>
      </onfalse>
    </selection>
  </sequence>
</nsscheme>
