const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <title>WiFi Switch</title>
    <style>
      html {
        font-family: Georgia;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
      }
      .button {
        border: none;
        width: 220px;
        color: white;
        padding: 16px;
        text-decoration: none;
        font-size: 30px;
        margin: 2px;
        cursor: pointer;
        border-radius: 8px;
      }
      .button1 {
        background-color: #37ba3a;
      }
      .button2 {
        background-color: #e22248;
      }
      .button1:hover {
        background-color: #31992f;
      }
      .button1:active {
        transform: translateY(1px);
        background-color: #31992f;
      }
      .button2:hover {
        background-color: #b52441;
      }
      .button2:active {
        transform: translateY(1px);
        background-color: #b52441;
      }
      .container {
        position: absolute;
        top: 50%;
        left: 50%;
        -moz-transform: translateX(-50%) translateY(-50%);
        -webkit-transform: translateX(-50%) translateY(-50%);
        transform: translateX(-50%) translateY(-50%);
      }
    </style>
  </head>
  <link
    rel="icon"
    href="data:mage/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEYAAABGCAYAAABxLuKEAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAABLPSURB
                   VHhe7VwJcBzVmf67e3oOXdZlW7YlfEg+AGOzNpFYApgAdkhiwAnEy7nJ7mKTrSUhRQhU4t2wsIStXARCAlS87BZhYwI2CeAAxsCGGONDvrEBHxgfsmWhW9Y5Mz3d+32vZ3SORjPSiHKq8lW9et2
                   vW318/d/vjeSviA8t2o8qnMoif6uVPSbseApzPS1ljmj5GM7TNXsMej+aGW1BTRx0EsY5zWgt2G9Da7VFPxCyzZrAhceaecJoY1SIARFGrVWYEdC7/F4tNManhQosx5OPF5uMsTl44XF4/fG65h
                   Ti9Ew0L5oPrRMkkBkL59Sib0A7jbEG7O9AO2E7epVHszpwUguOtenlNSH0acdoEZPbYOVPM7TIuQG9c5lXC0/Hy+XgUIZ7xohAQv4EYt5GvwPEbFSjaUbaiAEZmWHbcx6+6jxc9jp81XxNc7Jxq
                   AikUE2MaEsHSE4HWhitEVL0v+hfNCqqD6NPC0ZMzOltZVkZTmeR5RjzDImUgYQKR/RLIS0BbFM9Rh2Oo72OD7KFDR/jIwwdN8qrR6RiIyPmkKOdap6bP9ZpWAzD+i0QM83UrNzo0U8VkJouEHMU
                   xPwIuy+DmEb3yPAwbGIeXb2i+LbiVbdkGJ2LsPs5d/TMQKuVVRlyvH88ahU/ccGC9fXR4ZSQMjE0rOiKOiIZ3/bpwblQmcnYn6AOniGAB6yDca5COLD7SMfkhzBUN/2yzafdo8khJWJat5bmZmo
                   dpbAdcyC6D9G4Ypvu9kwEXL50NoVz/yXsmJsLzKZqs+IEDXZS0KN9spgfEeMm9A/ja9DbnKmkEB589ex8s/k347z138R+uTucHJKSmEjlBEaqF+Nk3qAEhJShT5fr/TTQDunZhI+6Att7zfKTXe
                   7w4BiSmJqN52XnIYw39dAynLwYQ+PQUnbDtg2C0do6bOkMOdIVFOlC3wFfYkVwLIJHJzRNPKDch8jHa2qS4dPEj1ZUkKpwD0AbvNavWu2spxsjucemfnZbQrVKhpipWUZ7RabR8QR2GbANS1LCF
                   ogIOnL0VERqmyLS0GJLdb0tp9DaOx3pxDEmA7qugRCwn6fLmCxdxuZqUjzOkMvmM2sYOZrtnFubI2M2gZiPo0NxkZAYeKApYPl+bC6B+jCkTxqUhLpmW/68MyRrNwTlUJUlx2psaUY6OFycPcUj
                   0yYZMnOyRxbM88qMyYbMwnaKaEV7Lije7/rLjw+akCYkJlI5cQUIISlzscuwPiH40jUNtuw8YMn+oxakw5Ij1bZU1USkFVLRhtQvhLx5uMiFD8wKUJJc1ZpQaEhpsSFXfsYrZSWeZNUtjEx9T8g
                   x1wQqjjEYjIu4xEBSKB0+W7TVOGEaiClxjwwE7UMQtqK2CapRF5EPj0bkT9tD6C05eNxSajJayMrQpARqdsMiv8wp88jsMlPyczS0xAThvRoQ63yIzcW+iirmXQMwGDHnoFuI9ogaSAC++M79YX
                   nmtS7Z/mFYdh1gXvfpIxOZ2dSJhnzn5ky55lLfkOQQkJrr0O0AOcfckR4MIIZZMr7xUmzeg4Oz3NGBaG235fUtIUXKui1BZURpQFtg+1MBX8jv1ZQXiiEEQ10P+5QK4MxguEUmjTXkvFKPXHWRT
                   z5/oU+mlyT0FXthQ+/Wy0+tj+53Ix4x56P7El7v+zg4oH7Cl2dbD1Le3ROSfYctqfwgrFwvXXI8mLCP2Rm6Ev0JsAO0EdwmIRynF/LBNcdg4+aNp21lwGMei/ufwH41g3juJwJtTRkIITFf+Zxf
                   ebWczAGvStBlPwCb81sknSfcIRfxiLkd3VVoS9RAP/ABj8OY/sMDp1XP/aGQjYfil6QHuRyGcsZZhpSMN2RioY5juhiDSH0N3XlDBN4sIrsPWrLpPdiuI5acqE1emn5+V7YsqvDJOVPjey9IzCq
                   0V0DMquiQQjcxIIQyl42TnkM/Hwa3QB3oBdqQl+F6H3u+HR4o8VcjCbOmwGPgob54kVfG5xuS4Y/71VICpeXAsYg8/2aXIorhwFCYf7ap3PvP7mQYNgCUmh1aec2l7q6L7idt3zqVec/cgNb1BE
                   iZgW0WqRUo0gePR2Tlix3KpuyEgQ3FsbG5yo0a8mWI78yYVIzVpRi9H/GZx+ghhuoSgvoxCua1wnDjpNqESvmhWrnZ8cWI0XNLmy1HTvYEif+9tlMOwQMyVIiHwlxdzsIzLL3SL19bHOjv1mHR5
                   BDacrTdIKiNg91PGtpaMha6dq1XCzF2mRIdVqhttOUlSMqjz7XLxycifXRcGT003oy6TJG9Y2mmTBqnQ0rcB6DtCeLFI3DtbbAZfDFutyKuOY0UIYiPzqiYV2UaEEDCwciXRNIOMUWgTeILxsO/
                   r2yTHZDmPYcsZbTj2SBeZzaM8soVOehNdc1eOIXGmOYZEKMKXN3EQJWmonsYjUUnTmt0g/HIjf/aovS7/01pH2hDbv9Khlw810TzDvjaNKB1iHOYDrwN0adL/wiRML92K9I7SkE8MCUgwVRLpgR
                   XlntV9BsPtHe7D4blvl+3Q9UGPmcMK1eMUc85q+91VIEd7S4Qc4QDihiQEoBtmYPNFyAtnNLokyTyRjesaFa63fuGASR3DNGXfzmgPABjh/wxrjHleTSeb24LKVvAB2ejxDBvonoyCqZKqQmTOK
                   D7pURmwaVnwXvRpU+ZYMglf+NVatHb25BcXo/3+OlvO2QTPOYH+JD98chdOYrkudP7EAP5FcTpnkVm+QkGfm5CeN+y7HEgpAyP8fe4DbO1bkki+OAk51BVDzEFIKD8XK98Bobt2gV+KZ3kUZJCt
                   aKu70JaoGKczZAQeBRKC70JieE1GDEPRkgMPM5GVaNkNcHgn6yzFbHcV64bBE8CQbyv6XHVjarLZJTnMF8jaPgnIoWg/TsLfobP3wt8X0ZSa+9dXlj30MrmUIyY6Tg2D+SwrNCHFIIPxwu9WRmE
                   e3bf5mzYkn+6NiBfvzoD7tejHioGeq/fre+SZ9E27g4pvaeEpAOUDErFhl2u6yYxV/1t3yoI1aQA0stjW/a5XoLEfBZq/ncL/TIFEXJvRwBEiXE2mhJpvn9lW706ClViQZspwN3cT4RYHEOR5s1
                   oLAlGwjsgIS/9OSiP/C7pCmJacP4MjyxbkiELERr0j3SZ2PLDkFBm5YkQdsyHI6K/geRynXoru3LCraDnaux8VZ2RANRjqgP1PsY6o97Vb3XJlr0hfMlwXN3uDUofRZ7k5iHp47UykTUTDsSTKY
                   GblLqJKT9EIjBxpATPnW7KN5dmKImgFyL4vHw+Sj2NeSIguVwD4VmLYO83MWK+je5aqNJl3E8FLCUwMv3JM22wKZbsRYrQHzTGOYhwfbBefLjJ0PGJ8Dazp3mUW+YxlhQIKpxrROHFql1S9h4Ow
                   1a4ns2GtaZ96g8aaYYMD9yejTTAh5gK9i4xD/GwAe0FeKZfqKeBKt2L7nq0C7ifCvjgP/h1mypGDZYe0J0zsaOoL1ngU8Yvmey3Nx57vkNe3xxUrp5uPhFeeSRPys8xB417EmA72hoQ86PYX7LY
                   TTedMk7D8m9AbNIRJ26gilwAr/X4vTny429lyzcQ61DPOZ4qblzklye/lyOrHsyVu2/NTEgsE9sTtYnVbxCwnq0qlbGr02INq6hKXaYRpg73Bu1H+bmmXHOJT+bPMiExphJ1xj50pZQuFrPotdZ
                   vCcrad9z2xtagvAOPsw0Ze9UniHu44APg12fccuFsUxYi0FtyGRJDqKIvaktioEpRdWmnUoXlGD40lQrF3DW8kjYH14ybZSUCJWYHbAtfgvFGDAsQRC2+xC+3wVswfiAhMdAYNsBmrNsSklffDS
                   IMCMkr6GNRMe0UbQxfmiWL3ipBg19ajAQVksfjJLB30Em7snRhQHmnVFWpy/EjZTPf/8+nml5TT2tXFv0C3S3YyeN+KqAbpKv+2ap2JHZuxZ+lhf7hO90mg7P/QiK6cU9YDiAp5d8NBaoMbdKdN
                   zDlYG23xx3zXg2QvPth4+qRUDJ0uBoSuvji5Cp4cVCNtgo25rtRYiYgR3Juws547qcCqlDYcpRetyOgYlQ6oRA5ztiecP29jyzZ9n5Y3toelD2IghkZM4Hk3w0FvixtEpPTcqgRjSqDNCJWb2aO
                   1AVppbQwiy4Zz+KXe+8UcRKp0bN6+SmXGGvrxId0zYHEDF70Hg6YUTMs//3bQRXjrPm/LrU/XJQVw8ac55X7bsvqIznpAkg5iu55EHOvkjfL8bRbtmdE60nigSQwLfj5qjZ57o2RkUJ8dCIiL77
                   dJct+2ILsfFheJyEcR+PqLDXXpIgBU4145DpupxOMXp95tVMVyiny8cBiOCNVerArYJvodRKF7oy6mYu9uik4ZISdKvCEtWhquYgixtDsNqhS3PmVkYA2gNErjWTvmguLRHTdl5zvVVEqg77rLv
                   ej98v1V/jVPNH12KfnYeG8P0gO859UZxKGhkZSVAVPEWNq4dMezUq7xDgI3+k1+ofwNIwFcKVM/B78Rrb88J+z5R4EbXcgz+G80Pe/nik/uTNbrqxwZxjjgWlDvPLqCIEgQu+RGKAK7aC7mT6ML
                   zAQI2X1qbEyE/7VPTny5i/z5dYvurWR/kVyEscA8bG7c+QJRM133dSzDIfxEK9BybpoDkso6YOhRfZDSNTkm3oi5EoT0VXA1rCCNyw/Fw8M5Fjg4sxCCwwvVej86R4VCbNA3jvoGwyMkA/D6L4G
                   mxKCezcR4M2cbCBOQqKIxLNfXWW4oE5yzQwXRW1DHFMdI8YXLW2uBzFpX3XJIjXtDCfWOHvAiNXAC3FmgKrGY1QLmmeWL1URHKRx3ikGEuwacE7F6pIRGHw+ahgIotGUMJF+D8R0dtONII8zAz8
                   FMVegH/UlqZwViLlfhvWb94VVwMcyxEQEhyybMtrtTc4oIn4xnAAxzLBvBjHfQz+qqzBP1rkzi/evbFNRMElqQsrAKJrRK8uknC6ZN9Mjt3whIDdfFYj+5ajhCDTmQcjsWr28Rjmh3p+D9ch9aF
                   wXO/T03jBBldmLFIFl0Pc/thRJLFjTc9Glx2YQOJdF8phxc458tABC8Fm0FnyTD9B312S7iUHUF0bbhYOn0LjqaFTATJjTqqvWdSoCBlsIQFCaSOBTL3dGR9IPvHM7ot16XZz9aN2LFruJMSqqI
                   2jNOOkF7LLENyogKZVIKDlHlQxYIfwD7NBoQdfsDXDTrNo1o3U/VBzL5mwFObstx2iKDqQVjFaZCScLqhgli257sLRiuIg4OhRW34XNre5IDwYQg/TgkC3aTvwBJ7rTDkasVmzpapLgPDdtU/8I
                   eqTAOx4FOVy9OeBdBxADceqAjdmLzUEX7o0ERXC/qdR8GRSymM7omQlnOgEheBqNS0Dao0PdiKNKCLLcNWlvddm+d8FqWssRjE84351s2bGs2KPqxmnGcXx8/kLuWbSTaqQfBn06rmaMiP5HCD1
                   FLW35PSfHWGxijDIUODfEBYeXX5Cexc9RdMBUHIYNfdUor65Di/urlISfzauFn4QL293bv48UnFVglf8frxk6aGOJdA5yKy4aSBfwLi22Y7y/vXPu/0SH4mJIpbUri7hykz+wWOmOpAdMCBmnPP
                   lChwrkmAs1nXZkLFKCkiJdFbSpQlyh1T/7HiZoulsjjvEdaMJmaIRa7jEYkiEmFycVY/MWtK+hFXF8pOC6GK5G4ApyLufgLAI9jx/mhERwmRoL29xPQwbNAIGrptaAlKdBThWISfj77aTuiOybs
                   jwb7T/QLkbLQvtLASWF7pgOhZ52J7zQkNXKlD4FCOLcNlNzznX/pYCS8RRsyyt6+Slm0EkhOZ/Zg31h8TxuiXFj2PbU4masY5yRQPTeEbLNOuRCP8BzrsbQTvdIckiJGIhgV0SMOks8m3kz3JxJ
                   J//NwJmGetEchPraS3i+jSDnMKQlpWL/sK1asLIkF75vuSbOl0zN6rN4+AwAl3OsQ3sKH5OTaCljxOa+Y/MUriBfYhrh5brYpYh7Bqwo/5TQAQk+2hjOfbQxnPeHmRs31su/acPOOtNBDMPSyV4
                   jNBOkzIIEzQs7nusMsQ2k9OmfR+0LRENaCPd8Cdv7sX2oIZS3oy5UcOycy98Zkf0bMTG9Aa/FeGcBcqw7PJpV6NEi/PUKF+Kky73T9bKFENZzZSUnx/hvVB5H/wHawXgJ4XCQVmJ6I1w5iT/U4B
                   LZGyBJ/M1zOshhakIjeqAlkr06bJvvFZqN+0BG2v/ZzmgSw9mwDNidQpDDgsE07JdC3GdEHH0stnMgUXnwGOOhen7L8eB8TXx6MGhokRDO45f/BH/L4nQ97Md2TXNOYp8FtIZ2O9DaHskMjjPrW
                   0FMmis1o0hMf0DN+PuEUqhACULyHBCS6dXDY/DCedj3dtmcddLErwfDps6JFI2FXpLQCjLqkQ3vJymGZpOI0SsC/xWJIPL/L42ICnlN5h8AAAAASUVORK5CYII="
  />
  <body onload="initApp()">
    <div class="container">
      <h1>WiFi Switch</h1>
      <button class="button button1" id="state_btn" onclick="sendData(1)">Turn ON</button>
      <p>WiFi Switch Status: <span id="state_text">OFF</span></p>
    </div>
    <script>
      var pin_state = 0;

      function setStateHtml() {
        if (pin_state == 1) {
          document.getElementById('state_btn').innerText = 'TURN OFF';

          document.getElementById('state_btn').classList.remove('button1');
          document.getElementById('state_btn').classList.add('button2');
        } 
        else {
          document.getElementById('state_btn').innerText = 'TURN ON';

          document.getElementById('state_btn').classList.remove('button2');
          document.getElementById('state_btn').classList.add('button1');
        }

        document.getElementById('state_text').innerText = pin_state == 1 ? 'ON' : 'OFF';
      }
      function sendData() {
        var new_pin_state = pin_state == 1 ? 0 : 1;

        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState  == 4 && this.status  == 200) {
            console.log('sending state to esp:' + new_pin_state);
            pin_state = new_pin_state;
            setStateHtml();
          }
        };
        xhttp.open('GET', 'setRelay?relayState=' + new_pin_state, true);
        xhttp.send();
      }

      function initApp() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            pin_state = +this.responseText; //  + use for type convert to int
            setStateHtml();
          }
        };
        xhttp.open('GET', 'getRelayState', true);
        xhttp.send();

        setStateHtml();
      }
    </script>
  </body>
</html>

)=====";
