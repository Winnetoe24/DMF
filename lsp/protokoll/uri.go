package protokoll

import (
	"fmt"
	"net/url"
	"runtime"
	"strings"
)

// DocumentURI represents the URI of a document
type DocumentURI string

// Parse converts the DocumentURI to a url.URL structure
func (uri DocumentURI) Parse() (*url.URL, error) {
	return url.Parse(string(uri))
}

// Scheme returns the scheme component of the URI (e.g., "file", "http")
func (uri DocumentURI) Scheme() (string, error) {
	u, err := uri.Parse()
	if err != nil {
		return "", err
	}
	return u.Scheme, nil
}

// Authority returns the authority component of the URI (e.g., "example.com:8080")
func (uri DocumentURI) Authority() (string, error) {
	u, err := uri.Parse()
	if err != nil {
		return "", err
	}
	return u.Host, nil
}

// Path returns the path component of the URI
// For file URIs, this returns the file system path
func (uri DocumentURI) Path() (string, error) {
	u, err := uri.Parse()
	if err != nil {
		return "", err
	}

	// Handle Windows paths specially
	if u.Scheme == "file" {
		// Remove leading slash for Windows absolute paths
		path := u.Path
		if strings.HasPrefix(path, "/") && len(path) >= 3 && path[2] == ':' {
			path = path[1:]
		}
		return path, nil
	}

	return u.Path, nil
}

// Query returns the query component of the URI (after '?')
func (uri DocumentURI) Query() (string, error) {
	u, err := uri.Parse()
	if err != nil {
		return "", err
	}
	return u.RawQuery, nil
}

// QueryParams returns the parsed query parameters as a map
func (uri DocumentURI) QueryParams() (url.Values, error) {
	u, err := uri.Parse()
	if err != nil {
		return nil, err
	}
	return u.Query(), nil
}

// Fragment returns the fragment component of the URI (after '#')
func (uri DocumentURI) Fragment() (string, error) {
	u, err := uri.Parse()
	if err != nil {
		return "", err
	}
	return u.Fragment, nil
}

// IsFile returns true if the URI has a "file" scheme
func (uri DocumentURI) IsFile() bool {
	scheme, err := uri.Scheme()
	if err != nil {
		return false
	}
	return scheme == "file"
}

// ToFilePath converts a file URI to a file system path
func (uri DocumentURI) ToFilePath() (string, error) {
	if !uri.IsFile() {
		return "", fmt.Errorf("URI is not a file URI: %s", uri)
	}

	path, err := uri.Path()
	if err != nil {
		return "", err
	}

	// Handle Windows paths
	if runtime.GOOS == "windows" {
		// Convert forward slashes to backslashes
		path = strings.ReplaceAll(path, "/", "\\")
	}

	return path, nil
}

// FromFilePath creates a DocumentURI from a file system path
func FromFilePath(path string) DocumentURI {
	// Convert backslashes to forward slashes for Windows paths
	path = strings.ReplaceAll(path, "\\", "/")

	// Ensure path starts with a slash
	if !strings.HasPrefix(path, "/") {
		path = "/" + path
	}

	return DocumentURI("file://" + path)
}
