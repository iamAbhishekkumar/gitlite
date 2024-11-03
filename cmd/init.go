package cmd

import (
	"fmt"
	"os"

	"github.com/iamAbhishekkumar/gitlite/core"
	"github.com/spf13/cobra"
)

var initCmd = &cobra.Command{
	Use:   "init [directory]",
	Short: "Initialize a new, empty repository.",
	Args:  cobra.MaximumNArgs(1), // Allow 0 or 1 argument
	Run: func(cmd *cobra.Command, args []string) {
		var path string
		if len(args) > 0 {
			path = args[0]
		} else {
			// NEED TO CHANGE
			os.Mkdir("sample", 0755)
			path = "sample" // Default to current directory
		}
		// Add your repository initialization logic here
		fmt.Printf("Initializing a new repository in %s\n", path)
		core.RepoCreate(path)
	},
}
