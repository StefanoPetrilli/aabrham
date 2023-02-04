var aabrham = angular.module('aabrham', []);

aabrham.controller('SignupController', function SignupController($scope, $http) {
    $scope.signup = function(username, password){
        $http.get("/signup/api/" + username + "/" + password).then(function (result) {
            result.data.result ?
                window.location.href = "/homepage" :
                $scope.failedLogin = true

            $scope.loginError = result.data.error;
        });
    }
});