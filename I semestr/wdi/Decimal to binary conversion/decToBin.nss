<!DOCTYPE nsscheme>
<nsscheme type="sequence">
  <position>
    <x>4</x>
    <y>30</y>
  </position>
  <size>
    <width>2025</width>
    <height>1057</height>
  </size>
  <name>Konwersja dec -> bin</name>
  <comment></comment>
  <author>Grzegorz Gil</author>
  <pascalCode contains="yes"/>
  <checkSyntax enabled="yes"/>
  <variables>
    <variable>
      <name>b1</name>
      <type>
        <double/>
      </type>
      <value>1</value>
    </variable>
    <variable>
      <name>b2</name>
      <type>
        <double/>
      </type>
      <value>0</value>
    </variable>
    <variable>
      <name>b3</name>
      <type>
        <double/>
      </type>
      <value>1</value>
    </variable>
    <variable>
      <name>b4</name>
      <type>
        <double/>
      </type>
      <value>1</value>
    </variable>
    <variable>
      <name>b4b3b2b1</name>
      <type>
        <double/>
      </type>
      <value>nan</value>
    </variable>
    <variable>
      <name>input</name>
      <type>
        <double/>
      </type>
      <value>0.8125</value>
    </variable>
  </variables>
  <sequence>
    <inputinstruction>
      <text>input</text>
      <comment>Podaj liczbę całkowitą mniejszą od 16</comment>
    </inputinstruction>
    <selection instructionsheight="885" conditionheight="82">
      <condition>
        <text>input > 15</text>
        <comment>Jeśli wprowadzone dane są niepoprawne</comment>
      </condition>
      <ontrue>
        <sequence>
          <outputinstruction>
            <text>'Podana wartość jest niepoprawna'</text>
            <comment></comment>
          </outputinstruction>
        </sequence>
      </ontrue>
      <onfalse>
        <sequence>
          <selection instructionsheight="820" conditionheight="59">
            <condition>
              <text>input = 15</text>
              <comment></comment>
            </condition>
            <ontrue>
              <sequence>
                <outputinstruction>
                  <text>'1111'</text>
                  <comment></comment>
                </outputinstruction>
              </sequence>
            </ontrue>
            <onfalse>
              <sequence>
                <selection instructionsheight="711" conditionheight="103">
                  <condition>
                    <text>input = 14</text>
                    <comment></comment>
                  </condition>
                  <ontrue>
                    <sequence>
                      <outputinstruction>
                        <text>'1110'</text>
                        <comment></comment>
                      </outputinstruction>
                    </sequence>
                  </ontrue>
                  <onfalse>
                    <sequence>
                      <selection instructionsheight="616" conditionheight="89">
                        <condition>
                          <text>input = 13</text>
                          <comment></comment>
                        </condition>
                        <ontrue>
                          <sequence>
                            <outputinstruction>
                              <text>'1101'</text>
                              <comment></comment>
                            </outputinstruction>
                          </sequence>
                        </ontrue>
                        <onfalse>
                          <sequence>
                            <selection instructionsheight="533" conditionheight="77">
                              <condition>
                                <text>input = 12</text>
                                <comment></comment>
                              </condition>
                              <ontrue>
                                <sequence>
                                  <outputinstruction>
                                    <text>'1100'</text>
                                    <comment></comment>
                                  </outputinstruction>
                                </sequence>
                              </ontrue>
                              <onfalse>
                                <sequence>
                                  <selection instructionsheight="460" conditionheight="67">
                                    <condition>
                                      <text>input = 11</text>
                                      <comment></comment>
                                    </condition>
                                    <ontrue>
                                      <sequence>
                                        <outputinstruction>
                                          <text>'1011'</text>
                                          <comment></comment>
                                        </outputinstruction>
                                      </sequence>
                                    </ontrue>
                                    <onfalse>
                                      <sequence>
                                        <selection instructionsheight="397" conditionheight="57">
                                          <condition>
                                            <text>input = 10</text>
                                            <comment></comment>
                                          </condition>
                                          <ontrue>
                                            <sequence>
                                              <outputinstruction>
                                                <text>'1010'</text>
                                                <comment></comment>
                                              </outputinstruction>
                                            </sequence>
                                          </ontrue>
                                          <onfalse>
                                            <sequence>
                                              <selection instructionsheight="342" conditionheight="49">
                                                <condition>
                                                  <text>input = 9</text>
                                                  <comment></comment>
                                                </condition>
                                                <ontrue>
                                                  <sequence>
                                                    <outputinstruction>
                                                      <text>'1001'</text>
                                                      <comment></comment>
                                                    </outputinstruction>
                                                  </sequence>
                                                </ontrue>
                                                <onfalse>
                                                  <sequence>
                                                    <selection instructionsheight="293" conditionheight="43">
                                                      <condition>
                                                        <text>input = 8</text>
                                                        <comment></comment>
                                                      </condition>
                                                      <ontrue>
                                                        <sequence>
                                                          <outputinstruction>
                                                            <text>'1000'</text>
                                                            <comment></comment>
                                                          </outputinstruction>
                                                        </sequence>
                                                      </ontrue>
                                                      <onfalse>
                                                        <sequence>
                                                          <selection instructionsheight="251" conditionheight="36">
                                                            <condition>
                                                              <text>input = 7</text>
                                                              <comment></comment>
                                                            </condition>
                                                            <ontrue>
                                                              <sequence>
                                                                <outputinstruction>
                                                                  <text>'0111'</text>
                                                                  <comment></comment>
                                                                </outputinstruction>
                                                              </sequence>
                                                            </ontrue>
                                                            <onfalse>
                                                              <sequence>
                                                                <selection instructionsheight="212" conditionheight="33">
                                                                  <condition>
                                                                    <text>input = 6</text>
                                                                    <comment></comment>
                                                                  </condition>
                                                                  <ontrue>
                                                                    <sequence>
                                                                      <outputinstruction>
                                                                        <text>'0110'</text>
                                                                        <comment></comment>
                                                                      </outputinstruction>
                                                                    </sequence>
                                                                  </ontrue>
                                                                  <onfalse>
                                                                    <sequence>
                                                                      <selection instructionsheight="173" conditionheight="33">
                                                                        <condition>
                                                                          <text>input = 5</text>
                                                                          <comment></comment>
                                                                        </condition>
                                                                        <ontrue>
                                                                          <sequence>
                                                                            <outputinstruction>
                                                                              <text>'0101'</text>
                                                                              <comment></comment>
                                                                            </outputinstruction>
                                                                          </sequence>
                                                                        </ontrue>
                                                                        <onfalse>
                                                                          <sequence>
                                                                            <selection instructionsheight="134" conditionheight="33">
                                                                              <condition>
                                                                                <text>input = 4</text>
                                                                                <comment></comment>
                                                                              </condition>
                                                                              <ontrue>
                                                                                <sequence>
                                                                                  <outputinstruction>
                                                                                    <text>'0100'</text>
                                                                                    <comment></comment>
                                                                                  </outputinstruction>
                                                                                </sequence>
                                                                              </ontrue>
                                                                              <onfalse>
                                                                                <sequence>
                                                                                  <selection instructionsheight="95" conditionheight="33">
                                                                                    <condition>
                                                                                      <text>input = 3</text>
                                                                                      <comment></comment>
                                                                                    </condition>
                                                                                    <ontrue>
                                                                                      <sequence>
                                                                                        <outputinstruction>
                                                                                          <text>'0011'</text>
                                                                                          <comment></comment>
                                                                                        </outputinstruction>
                                                                                      </sequence>
                                                                                    </ontrue>
                                                                                    <onfalse>
                                                                                      <sequence>
                                                                                        <selection instructionsheight="56" conditionheight="33">
                                                                                          <condition>
                                                                                            <text>input = 2</text>
                                                                                            <comment></comment>
                                                                                          </condition>
                                                                                          <ontrue>
                                                                                            <sequence>
                                                                                              <outputinstruction>
                                                                                                <text>'0010'</text>
                                                                                                <comment></comment>
                                                                                              </outputinstruction>
                                                                                            </sequence>
                                                                                          </ontrue>
                                                                                          <onfalse>
                                                                                            <sequence>
                                                                                              <selection instructionsheight="17" conditionheight="33">
                                                                                                <condition>
                                                                                                  <text>input = 1</text>
                                                                                                  <comment></comment>
                                                                                                </condition>
                                                                                                <ontrue>
                                                                                                  <sequence>
                                                                                                    <outputinstruction>
                                                                                                      <text>'0001'</text>
                                                                                                      <comment></comment>
                                                                                                    </outputinstruction>
                                                                                                  </sequence>
                                                                                                </ontrue>
                                                                                                <onfalse>
                                                                                                  <sequence>
                                                                                                    <outputinstruction>
                                                                                                      <text>'0000'</text>
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
                                                                              </onfalse>
                                                                            </selection>
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
                                                      </onfalse>
                                                    </selection>
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
                              </onfalse>
                            </selection>
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
      </onfalse>
    </selection>
  </sequence>
</nsscheme>
