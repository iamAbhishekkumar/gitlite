package utils

import (
	"log"

	"gopkg.in/ini.v1"
)

func addKey(cfg *ini.File, section, key, value string) {
	_, err := cfg.Section(section).NewKey(key, value)
	if err != nil {
		log.Fatalf("Failed to set %s in %s section: %v", key, section, err)
	}
}
