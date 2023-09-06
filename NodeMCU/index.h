const char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta charset='utf-8'>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
  <title>Test Sitesi</title>
  <link rel='icon' type='image/png' href='https://upload.wikimedia.org/wikipedia/tr/thumb/2/28/Hacettepe_%C3%9Cniversitesi_Logosu.svg/1200px-Hacettepe_%C3%9Cniversitesi_Logosu.svg.png'/>
  <style>
    html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}
    body { margin-top: 50px; }
    h1 { color: #40F8FF; margin: 50px auto 30px; }
    p { font-size: 14px; color: #D5FFD0; margin-bottom: 10px; }
    .veri{ color:#D5FFD0; display:flex; flex-direction:column; justify-content:center; align-items:center; gap:10px;}

    .html {
      text-align: center;
      font-size: 5px;
      width: 50px;
      height:50px;
      display:flex;
      justify-content:center;
      align-items:center;
    }

    .body {
      margin: 0;
      font-size: 1rem;
      display: flex;
      flex: 1;
      align-items: center;
    }

    .large-button {
        font-size: 18px;
    }

    .clock {
      position: relative;
      padding: 2rem;
      margin: 50px auto;
    }

    .hand {
      right: 50%;
      height: 4px;
      background: #279EFF;
      position: absolute;
      top: 50%;
      border-radius: 6px;
      transform-origin: 100%;
      transform: rotate(180deg);
      transition-timing-function: cubic-bezier(0.1, 2.7, 0.58, 1);
    }

    .hand.first-hand {
      width: 50px;
      z-index: 3;
    }

    .hand.second-hand {
      width: 50px;
      z-index: 4;
    }

    .degreeValue {
      height: 3px;
      z-index: 10;
      width: 40%;
      color: #888;
      position: absolute;
      top: 50%;
      right: 10%;
      transform-origin: 100%;
      transform: translate(50px, -5px);
    }

  </style>
</head>
<body bgcolor="0C356A" style="color: white;">
  <div id="webpage">
    <img src="https://upload.wikimedia.org/wikipedia/tr/thumb/2/28/Hacettepe_%C3%9Cniversitesi_Logosu.svg/1200px-Hacettepe_%C3%9Cniversitesi_Logosu.svg.png" width="96" height="142" alt="logo">
    <h1>ESP8266 NodeMCU Biomech Project</h1>
    <p>Site Ömer Kenan Uçmaklıoğlu tarafından hazırlanmıştır.</p>
    <button id="kalibrasyonButton" class="large-button" style="
        padding-left: 35px;
        padding-right: 35px;
        padding-top: 10px;
        padding-bottom: 10px;
    ">Kalibre et</button>
    <div class="veri"><p>Gyro 1 Pitch: <span id="pitch1">0</span></p>
    <div class="html">
      <div class="body">
        <div class="clock">
            <div class="hand first-hand"></div>
            <div class="hand second-hand pitch1"></div>
            <div class="degreeValue"></div>
        </div>
      </div>
    </div>
    <div class="veri"><p>Gyro 1 Roll: <span id="roll1">0</span></p>
    <div class="html">
      <div class="body">
        <div class="clock">
            <div class="hand first-hand"></div>
            <div class="hand second-hand roll1"></div>
            <div class="degreeValue"></div>
        </div>
      </div>
    </div>
    <div class="veri"><p>Gyro 2 Pitch: <span id="pitch2">0</span></p>
    <div class="html">
      <div class="body">
        <div class="clock">
            <div class="hand first-hand"></div>
            <div class="hand second-hand pitch2"></div>
            <div class="degreeValue"></div>
        </div>
      </div>
    </div>
    <div class="veri"><p>Gyro 2 Roll: <span id="roll2">0</span></p>
    <div class="html">
      <div class="body">
        <div class="clock">
            <div class="hand first-hand"></div>
            <div class="hand second-hand roll2"></div>
            <div class="degreeValue"></div>
        </div>
      </div>
    </div>
    <div class="veri"><p>Flex 1 Voltage: <span id="flexVoltage1">0</span>&emsp;&emsp;Flex 1 Flexion Angle: <span id="flexAngle1">0</span></p>
    <div class="html">
      <div class="body">
        <div class="clock">
            <div class="hand first-hand"></div>
            <div class="hand second-hand flexAngle1"></div>
            <div class="degreeValue"></div>
        </div>
      </div>
    </div>
    <div class="veri"><p>Flex 2 Voltage: <span id="flexVoltage2">0</span>&emsp;&emsp;Flex 2 Flexion Angle: <span id="flexAngle2">0</span></p>
    <div class="html">
      <div class="body">
        <div class="clock">
            <div class="hand first-hand"></div>
            <div class="hand second-hand flexAngle2"></div>
            <div class="degreeValue"></div>
        </div>
      </div>
    </div>
    <div class="veri"><p>Flex 3 Voltage: <span id="flexVoltage3">0</span>&emsp;&emsp;Flex 3 Flexion Angle: <span id="flexAngle3">0</span></p>
    <div class="html">
      <div class="body">
        <div class="clock">
            <div class="hand first-hand"></div>
            <div class="hand second-hand flexAngle3"></div>
            <div class="degreeValue"></div>
        </div>
      </div>
    </div>
    <div class="veri"><p>Flex 4 Voltage: <span id="flexVoltage4">0</span>&emsp;&emsp;Flex 4 Flexion Angle: <span id="flexAngle4">0</span></p>
    <div class="html">
      <div class="body">
        <div class="clock">
            <div class="hand first-hand"></div>
            <div class="hand second-hand flexAngle4"></div>
            <div class="degreeValue"></div>
        </div>
      </div>
    </div>
    <div class="veri"><p>Flex 5 Voltage: <span id="flexVoltage5">0</span>&emsp;&emsp;Flex 5 Flexion Angle: <span id="flexAngle5">0</span></p>
    <div class="html">
      <div class="body">
        <div class="clock">
            <div class="hand first-hand"></div>
            <div class="hand second-hand flexAngle5"></div>
            <div class="degreeValue"></div>
        </div>
      </div>
    </div>
    
    <br/><br/>

  <script>
    function sendKalibrasyonRequest() {
      const request = new XMLHttpRequest();
      request.open("POST", "/buttondata", true);
      request.setRequestHeader("Content-Type", "text/plain"); // Metin içeriği olarak belirtiyoruz
      
      const data = "Kalibrasyon"; // Metin verisi
      
      request.send(data); // Metin verisini gönderiyoruz
    }
    const kalibrasyonButton = document.getElementById("kalibrasyonButton");
    kalibrasyonButton.addEventListener("click", function() {
      sendKalibrasyonRequest();
    });
    function getDegreeData(endpoint,targetElement) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          let degree = this.responseText;
          document.getElementById(targetElement).innerHTML = degree;
          const secondHand = document.getElementsByClassName(targetElement)[0];

          secondHand.style.transform = `rotate(${180 - degree}deg)`;
        }
      };
      xhttp.open("GET", endpoint, true);
      xhttp.send();
    } 
    function updateRotation(targetElement, pitchValue) {
      const rotationAngle = 180 - pitchValue;
      const secondHand = document.getElementsByClassName(targetElement)[0];
      secondHand.style.transform = `rotate(${rotationAngle}deg)`;
    }

    function getData(endpoint, targetElement1, targetElement2, targetElement3, targetElement4, targetElement5, targetElement6, targetElement7, targetElement8, targetElement9, targetElement10, targetElement11, targetElement12, targetElement13, targetElement14) {
      fetch(endpoint)
        .then(response => response.text())
        .then(data => {
          const [pitch1Value, pitch2Value, roll1Value, roll2Value, flexVoltage1, flexAngle1Value, flexVoltage2, flexAngle2Value, flexVoltage3, flexAngle3Value, flexVoltage4, flexAngle4Value, flexVoltage5, flexAngle5Value] = data.split(" ");
          document.getElementById(targetElement1).innerHTML = pitch1Value;
          document.getElementById(targetElement2).innerHTML = pitch2Value;
          document.getElementById(targetElement3).innerHTML = roll1Value;
          document.getElementById(targetElement4).innerHTML = roll2Value;
          document.getElementById(targetElement5).innerHTML = flexVoltage1;
          document.getElementById(targetElement6).innerHTML = flexAngle1Value;
          document.getElementById(targetElement7).innerHTML = flexVoltage2;
          document.getElementById(targetElement8).innerHTML = flexAngle2Value;
          document.getElementById(targetElement9).innerHTML = flexVoltage3;
          document.getElementById(targetElement10).innerHTML = flexAngle3Value;
          document.getElementById(targetElement11).innerHTML = flexVoltage4;
          document.getElementById(targetElement12).innerHTML = flexAngle4Value;
          document.getElementById(targetElement13).innerHTML = flexVoltage5;
          document.getElementById(targetElement14).innerHTML = flexAngle5Value;
          
          updateRotation(targetElement1, parseFloat(pitch1Value));
          updateRotation(targetElement2, parseFloat(pitch2Value));
          updateRotation(targetElement3, parseFloat(roll1Value));
          updateRotation(targetElement4, parseFloat(roll2Value));
          updateRotation(targetElement6, parseFloat(flexAngle1Value));
          updateRotation(targetElement8, parseFloat(flexAngle2Value));
          updateRotation(targetElement10, parseFloat(flexAngle3Value));
          updateRotation(targetElement12, parseFloat(flexAngle4Value));
          updateRotation(targetElement14, parseFloat(flexAngle5Value));
        });
    }

    // Update the data every 20 second (20 milliseconds)
    setInterval(() => {
    getData("/pitchData", "pitch1", "pitch2","roll1","roll2","flexVoltage1","flexAngle1","flexVoltage2","flexAngle2","flexVoltage3","flexAngle3","flexVoltage4","flexAngle4","flexVoltage5","flexAngle5");
     }, 150);

    
  </script>
</body>
</html>
)=====";
