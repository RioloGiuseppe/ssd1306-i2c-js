{
    "targets": [{
        "target_name":
        "oledjs",
        "sources": [
            "oledjs.cc", "sources/ssd1306.c", "sources/ubuntuMono_8pt.c",
            "sources/ubuntuMono_12pt.c", "sources/ubuntuMono_16pt.c", 
            "sources/ubuntuMono_24pt.c", "sources/ubuntuMono_48pt.c"
        ],
        "include_dirs": ["<!(node -e \"require('nan')\")", "sources"],
        "link_settings": {
            "libraries": ["-lm"]
        }
    }]
}