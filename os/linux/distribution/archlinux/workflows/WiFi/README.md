wconfig wlan1 mode monitor


sudo ip link set dev wlan1 down
c
iwconfig wlan1 mode monitor



```shell
# 关闭短时间隔
ath0      IEEE 802.11ng  ESSID:"CLOUD.7052.WB"
          Mode:Master  Frequency:2.412 GHz  Access Point: C0:74:AD:95:11:D5
          Bit Rate:156 Mb/s   Tx-Power=24 dBm
          RTS thr:off   Fragment thr:off
          Encryption key:BCC0-1F73-68F5-33DE-FCC9-6785-659D-4BB1 [2]   Security mode:restricted
          Power Management:off
          Link Quality=10/100  Signal level:0 dBm  Noise level:0 dBm
          Rx invalid nwid:0  Rx invalid crypt:0  Rx invalid frag:0
          Tx excessive retries:0  Invalid misc:0   Missed beacon:0

# 开启短时间隔
ath0      IEEE 802.11ng  ESSID:"CLOUD.7052.WB"
          Mode:Master  Frequency:2.462 GHz  Access Point: C0:74:AD:95:11:D5
          Bit Rate:173 Mb/s   Tx-Power=24 dBm
          RTS thr:off   Fragment thr:off
          Encryption key:9996-09C9-39FF-C26C-6A6F-C7AE-9E36-1F49 [2]   Security mode:restricted
          Power Management:off
          Link Quality=10/100  Signal level:0 dBm  Noise level:0 dBm
          Rx invalid nwid:0  Rx invalid crypt:0  Rx invalid frag:0
          Tx excessive retries:0  Invalid misc:0   Missed beacon:0
```


* Probe
* Authentication
* Association
* EAPOL





sudo ip link set wlan0 down
sudo iwconfig wlan0 mode monitor
sudo ip link set wlan0 up





BSSID: CLOUD.7052.WB:@gwn7052 (C0:74:AD:95:11:D5)
STA1: 5E:43:CB:9D:60:47

wlan.ssid == "CLOUD.7052.WB" && wlan.fc.type_subtype == 0x08


wlan.fc.type == 0   # Management Frame
wlan.fc.type == 1   # Control Frame
wlan.fc.type == 2   # Data Frame

wlan.fc.type_subtype == 0x00    # Association Request Frame
wlan.fc.type_subtype == 0x01    # Association Response Frame
wlan.fc.type_subtype == 0x02    # Reassociation request Frame
wlan.fc.type_subtype == 0x03    # Reassociation response Frame
wlan.fc.type_subtype == 0x04    # Probe request Frame
wlan.fc.type_subtype == 0x05    # Probe response Frame

wlan.fc.type_subtype == 0x08    # Beacon Frame
wlan.fc.type_subtype == 0x0A    # Disassociate Frame
wlan.fc.type_subtype == 0x0B    # Authentication Frame
wlan.fc.type_subtype == 0x0C    # Deauthentication Frame
wlan.fc.type_subtype == 0x0D    # Action Frame
wlan.fc.type_subtype == 0x18    #

wlan.addr == 5E:43:CB:9D:60:47  # Address
wlan.sa == 5E:43:CB:9D:60:47    # Source Address
wlan.da == 5E:43:CB:9D:60:47    # Destination Address





Mediatek
--------
StateMachineSetAction

Set_MinDataRate_Proc -> UpdateBeaconHandler
RTMPUpdateRateInfo
APUpdateBeaconFrame

APPeerAuthReqAtIdleAction -> BndStrg_CheckConnectionReq

ApCliCtrlProbeRspAction
APPeerProbeReqAction -> BndStrg_CheckConnectionReq


ApCliPeerProbeRspAtJoinAction -> ApCliUpdateMlmeRate




Quallcom
--------

p2pkm_send_probe_resp