core/iw
extra/hostapd
extra/wireless_tools

















iw phy
iw phy phy2 info


iw list
iw features
iw commands

iw dev wlan2 info




sudo iw dev wlan2 interface add wlan1_ap type managed addr 12:34:56:78:ab:ce





* `/etc/hostapd/hostapd.conf`

```conf

bridge=br0
interface=wlan0

ssid=ArchLinux



```


* `/etc/hostapd/wlan0.conf`

```conf
# Interface
interface=wlan0

# SSID
ssid=ArchLinux

# WPA
wpa_passphrase=12345678
```