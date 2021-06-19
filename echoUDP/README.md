## Usage

Set up main.cpp with your WiFi credentials.

Every UDP packet sent to the board will be echoed.

To test it out, I recommend using `netcat`. For example:

```
$ nc -u 192.168.0.80 4133
test
test
hey
hey
```

