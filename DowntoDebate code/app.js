// Mobile menu toggle
const menu = document.querySelector('#mobile-menu');
const menuLinks = document.querySelector('.navbar__menu');

menu.addEventListener('click', function () {
    menu.classList.toggle('is-active');
    menuLinks.classList.toggle('active');
});

// Modal and form handling
const wrapper = document.querySelector('.wrapper');
const loginForm = document.querySelector('.form-box.login');
const registerForm = document.querySelector('.form-box.register'); // Make sure this line exists
const loginLink = document.querySelector('.login-link');
const closeIcon = document.querySelector('.icon-close'); // Ensure there's a close icon in your HTML
const loginPopupBtn = document.querySelector('.btnLogin-popup'); // Ensure this button exists
const getStartedButton = document.querySelector('.main__btn');

function openModal() {
    wrapper.style.display = 'block';  // Show the modal
    registerForm.classList.add('active');  // Show the registration form
    loginForm.classList.remove('active');  // Ensure login form is hidden
    wrapper.style.height = registerForm.scrollHeight + 50 + 'px';  // Adjust wrapper height dynamically
}

// Open the modal when the "Get Started" button is clicked
getStartedButton.addEventListener('click', openModal);

// Toggle to login form
loginLink.addEventListener('click', () => {
    registerForm.classList.remove('active');
    loginForm.classList.add('active');
    wrapper.style.height = loginForm.scrollHeight + 50 + 'px';  // Adjust wrapper height dynamically
});

// Close icon functionality
if (closeIcon) {
    closeIcon.addEventListener('click', () => {
        wrapper.style.display = 'none';  // Hide the entire login/register modal
    });
}

// Open the modal when the login button is clicked
if (loginPopupBtn) {
    loginPopupBtn.addEventListener('click', () => {
        wrapper.style.display = 'block';  // Show the modal
        loginForm.classList.add('active');  // Ensure the login form is active
        registerForm.classList.remove('active');  // Hide the register form
        wrapper.style.height = loginForm.scrollHeight + 50 + 'px';  // Adjust to login form's height
    });
}
