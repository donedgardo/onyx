# Onyx

Onyx is an exploration project demonstrating Test-Driven Development (TDD) and Continuous Integration (CI) principles applied within Unreal Engine. This repository centers on building a Dice Roller system using TDD practices, alongside leveraging Jenkins for automated CI workflows.

## Project Goals

The main goals of this project are:

1. **Explore TDD in Unreal Engine:** Investigating how TDD methodologies can be effectively utilized in Unreal Engine development.
2. **Establish CI with Jenkins:** Setting up a reliable CI pipeline with Jenkins to ensure smooth and automated testing, building, and integration.
3. **Demonstrate Best Practices:** Showcasing practical examples of TDD and CI to inspire and inform Unreal Engine developers.

---

## Features

- **Dice Roller System:**
  - A simple dice roller mechanic implemented using TDD principles.
  - Iterative development with test-first strategies to ensure robust functionality.

- **TDD Workflow:**
  - Unit tests written and executed to guide the development process.
  - Emphasis on code quality, maintainability, and reliability.

- **Jenkins CI Pipeline:**
  - Continuous integration pipeline for building and testing the project.
  - Automated unit tests triggered on code changes to catch issues early.

---

## Technologies Used

- **Unreal Engine:** Game engine for implementing the dice roller functionality.
- **Jenkins:** CI server for automating builds and tests.
- **Google Test Framework:** For implementing and running unit tests.
- **C++:** Primary language used for development.

---

## Getting Started

### Prerequisites

- Unreal Engine (version X.X or later)
- Jenkins CI server
- C++ development environment

### Setup

1. Clone the repository:

    ```bash
    git clone https://github.com/donedgardo/onyx.git
    cd onyx
    ```

2. Open the project in Unreal Engine.

3. Install and configure Jenkins if not already set up.

   - Set up a new Jenkins pipeline.
   - Configure build steps to include Unreal Engine project build and test commands.

---

## Running Tests

1. Navigate to the test folder in your project directory.

2. Run the unit tests:

    ```bash
    ./RunTests.sh
    ```

3. Alternatively, you can trigger tests automatically via Jenkins after pushing changes.

---

## CI with Jenkins

### Pipeline Overview

The Jenkins pipeline performs the following steps:

1. **Code Checkout:** Pulls the latest code from the repository.
2. **Build:** Compiles the Unreal Engine project.
3. **Unit Tests:** Executes automated unit tests for the dice roller.
4. **Results Reporting:** Provides a summary of the build and test results.

### Example Jenkinsfile

An example Jenkinsfile configuration:

```groovy
pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        stage('Build') {
            steps {
                sh './Build.sh'
            }
        }
        stage('Test') {
            steps {
                sh './RunTests.sh'
            }
        }
    }
    post {
        always {
            junit 'test-results.xml'
        }
    }
}
```

---

## Future Enhancements

- Extend the dice roller to support more complex mechanics and game rules.
- Explore additional testing strategies specific to Unreal Engine, such as integration and UI testing.
- Refine the CI pipeline with enhanced notifications and deployment steps.

---

## Contributing

Contributions are welcome! If you have suggestions, feel free to open an issue or submit a pull request.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

- Unreal Engine documentation for invaluable guidance.
- Jenkins community for excellent CI tools.
- Inspiration from TDD and CI best practices.
