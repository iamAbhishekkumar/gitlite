package cmd

import (
	"github.com/spf13/cobra"
)

// rootCmd is the base command when called without any subcommands.
var rootCmd = &cobra.Command{
	Use:   "gitlite",
	Short: "My CLI application",
}

// Execute adds all child commands to the root command and sets flags appropriately.
func Execute() error {
	return rootCmd.Execute()
}

// Initialize the command packages here
func init() {
	rootCmd.AddCommand(initCmd) // Add your init command here
	// Add other commands similarly
}
