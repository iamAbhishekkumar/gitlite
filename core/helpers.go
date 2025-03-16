package core

import (
	"log"
	"os"

	"gopkg.in/ini.v1"
)

func addKey(cfg *ini.File, section, key, value string) {
	_, err := cfg.Section(section).NewKey(key, value)
	if err != nil {
		log.Fatalf("Failed to set %s in %s section: %v", key, section, err)
	}
}

func FileExists(path string) error {
	if info, err := os.Stat(path); err == nil && !info.IsDir() {
		return nil // File exists
	} else {
		return err // File does not exist or other error
	}
}
